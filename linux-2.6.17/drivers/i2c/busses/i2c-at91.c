/*
    i2c Support for Atmel's AT91RM9200 Two-Wire Interface

    Copyright (C) 2004 Rick Bronson

    Borrowed heavily from original work by:
    Copyright (C) 2000 Philip Edelbrock <phil@stimpy.netroedge.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/pci.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/clk.h>
#include <linux/platform_device.h>

#include <asm/io.h>

#include <asm/arch/at91rm9200_twi.h>
#include <asm/arch/board.h>

#define AT91_TWI_CLOCK		100000
#define AT91_TWI_CKDIV1		(2 << 16)	/* TWI clock divider.  NOTE: see Errata #22 */


static struct clk *twi_clk;

/*
 * Read from a TWI register.
 */
static inline unsigned long at91_twi_read(unsigned int reg)
{
	void __iomem *twi_base = (void __iomem *)AT91_VA_BASE_TWI;

	return __raw_readl(twi_base + reg);
}

/*
 * Write to a TWI register.
 */
static inline void at91_twi_write(unsigned int reg, unsigned long value)
{
	void __iomem *twi_base = (void __iomem *)AT91_VA_BASE_TWI;

	__raw_writel(value, twi_base + reg);
}

static void at91_twi_hwinit(void)
{
	unsigned int sclock, cldiv2, cldiv3;

	at91_twi_write(AT91_TWI_IDR, 0x1ff);		/* Disable all interrupts */
	at91_twi_write(AT91_TWI_CR, AT91_TWI_SWRST);	/* Reset peripheral */
	at91_twi_write(AT91_TWI_CR, AT91_TWI_MSEN);	/* Set Master mode */

	sclock = (10 * clk_get_rate(twi_clk)) / AT91_TWI_CLOCK;
	cldiv2 = (sclock / 10) - 5;
	if ((sclock % 10) < 5)
		cldiv2 -= 1;
	cldiv3 = (cldiv2 + (4 - cldiv2 % 4)) >> 2;

	/* Here, CKDIV = 1 and CHDIV=CLDIV  ==> CLDIV = CHDIV = 1/4*((Fmclk/FTWI) -6) */
	at91_twi_write(AT91_TWI_CWGR, AT91_TWI_CKDIV1 | cldiv3 | (cldiv3 << 8));
}

/*
 * Poll the i2c status register until the specified bit is set.
 * Returns 0 if timed out (100 msec)
 */
static short at91_poll_status(unsigned long bit)
{
	int loop_cntr = 10000;

	do {
		udelay(10);
	} while (!(at91_twi_read(AT91_TWI_SR) & bit) && (--loop_cntr > 0));

	return (loop_cntr > 0);
}

/*
 * Generic i2c master transfer entrypoint
 */
static int at91_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
	struct i2c_msg *pmsg;
	int length;
	unsigned char *buf;
	int i;

	dev_dbg(&adap->dev, "at91_xfer: processing %d messages:\n", num);

	pmsg = msgs;		/* get 1st message */

	for (i = 0; i < num; i++) {
		dev_dbg(&adap->dev, " #%d: %sing %d byte%s %s 0x%02x ...", i,
			pmsg->flags & I2C_M_RD ? "read" : "write",
			pmsg->len, pmsg->len > 1 ? "s" : "",
			pmsg->flags & I2C_M_RD ? "from" : "to",	pmsg->addr);

		/*
		 * Set the TWI Master Mode Register:
		 *  We do _not_ use Atmel's feature of storing the "internal device address"
		 *  in TWI_IADR. Thus the IADRSZ bits in TWI_MMR are set to zero.
		 *  Instead the "internal device address" has to be written using a seperate
		 *  i2c message.
		 *  See http://lists.arm.linux.org.uk/pipermail/linux-arm-kernel/2004-September/024411.html
		 */
		at91_twi_write(AT91_TWI_MMR, (pmsg->addr << 16) | (pmsg->flags & I2C_M_RD ? AT91_TWI_MREAD : 0));

		length = pmsg->len;
		buf = pmsg->buf;
		if (length && buf) {	/* sanity check */
			if (pmsg->flags & I2C_M_RD) {
				at91_twi_write(AT91_TWI_CR, AT91_TWI_START);
				while (length--) {
					if (!length)
						at91_twi_write(AT91_TWI_CR, AT91_TWI_STOP);
					/* Wait until transfer is finished */
					if (!at91_poll_status(AT91_TWI_RXRDY)) {
						dev_dbg(&adap->dev, "timeout 1\n");
						return -ETIMEDOUT;
					}
					*buf++ = (at91_twi_read(AT91_TWI_RHR) & 0xff);
				}
				if (!at91_poll_status(AT91_TWI_TXCOMP)) {
					dev_dbg(&adap->dev, "timeout 2\n");
					return -ETIMEDOUT;
				}
			} else {
				at91_twi_write(AT91_TWI_CR, AT91_TWI_START);
				while (length--) {
					at91_twi_write(AT91_TWI_THR, *buf++);
					if (!length)
						at91_twi_write(AT91_TWI_CR, AT91_TWI_STOP);
					if (!at91_poll_status(AT91_TWI_TXRDY)) {
						dev_dbg(&adap->dev, "timeout 3\n");
						return -ETIMEDOUT;
					}
				}
				/* Wait until transfer is finished */
				if (!at91_poll_status(AT91_TWI_TXCOMP)) {
					dev_dbg(&adap->dev, "timeout 4\n");
					return -ETIMEDOUT;
				}
			}
		}
		dev_dbg(&adap->dev, "ok\n");
		pmsg++;	/* go to next message */
	}
	return i;
}

/*
 * Return list of supported functionality
 */
static u32 at91_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

/* For now, we only handle combined mode (smbus) */
static struct i2c_algorithm at91_algorithm = {
	.master_xfer	= at91_xfer,
	.functionality	= at91_func,
};

/*
 * Main initialization routine
 */
static int __init at91_i2c_probe(struct platform_device *pdev)
{
	struct i2c_adapter *adapter;
	int rc;

	twi_clk = clk_get(NULL, "twi_clk");
	if (IS_ERR(twi_clk)) {
		dev_err(&pdev->dev, "no clock defined\n");
		return -ENODEV;
	}

	adapter = kzalloc(sizeof(struct i2c_adapter), GFP_KERNEL);
	if (adapter == NULL) {
		dev_err(&pdev->dev, "can't allocate inteface!\n");
		return -ENOMEM;
	}
	sprintf(adapter->name, "AT91RM9200");
	adapter->algo = &at91_algorithm;
	adapter->class = I2C_CLASS_HWMON;
	adapter->dev.parent = &pdev->dev;

	platform_set_drvdata(pdev, adapter);

	clk_enable(twi_clk);			/* enable peripheral clock */
	at91_twi_hwinit();			/* initialize TWI controller */

	rc = i2c_add_adapter(adapter);
	if (rc) {
		dev_err(&pdev->dev, "Adapter %s registration failed\n", adapter->name);
		platform_set_drvdata(pdev, NULL);
		kfree(adapter);
		clk_disable(twi_clk);
	}
	else
		dev_info(&pdev->dev, "AT91 i2c bus driver.\n");

	return rc;
}

static int __devexit at91_i2c_remove(struct platform_device *pdev)
{
	struct i2c_adapter *adapter = platform_get_drvdata(pdev);
	int res;

	res = i2c_del_adapter(adapter);
	platform_set_drvdata(pdev, NULL);

	clk_disable(twi_clk);			/* disable peripheral clock */
	clk_put(twi_clk);

	return res;
}

static struct platform_driver at91_i2c_driver = {
	.probe		= at91_i2c_probe,
	.remove		= at91_i2c_remove,
	.driver		= {
		.name	= "at91_i2c",
		.owner	= THIS_MODULE,
	},
};

static int __init at91_i2c_init(void)
{
	return platform_driver_register(&at91_i2c_driver);
}

static void __exit at91_i2c_exit(void)
{
	platform_driver_unregister(&at91_i2c_driver);
}


module_init(at91_i2c_init);
module_exit(at91_i2c_exit);

MODULE_AUTHOR("Rick Bronson");
MODULE_DESCRIPTION("I2C driver for Atmel AT91RM9200");
MODULE_LICENSE("GPL");
