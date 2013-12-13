/*
 * (C) Copyright 2001
 * Rob Taylor, Flying Pig Systems. robt@flyingpig.com.
 *
 * (C) Copyright 2002
 * Gregory E. Allen, gallen@arlut.utexas.edu
 * Matthew E. Karger, karger@arlut.utexas.edu
 * Applied Research Laboratories, The University of Texas at Austin
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <mpc824x.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <asm/mmu.h>
#include <pci.h>

#define	SAVE_SZ	32


int checkboard(void)
{
	ulong busfreq  = get_bus_freq(0);
	char  buf[32];

	printf("Board: UTX8245 Local Bus at %s MHz\n", strmhz(buf, busfreq));
	return 0;
}


long int initdram(int board_type)
{
#if 1
	int				i, cnt;
	volatile uchar	*base =	CFG_SDRAM_BASE;
	volatile ulong	*addr;
	ulong			save[SAVE_SZ];
	ulong			val, ret  = 0;
/*
	write_bat(IBAT1, ((CFG_MAX_RAM_SIZE/2) | BATU_BL_256M | BATU_VS | BATU_VP),
			( (CFG_MAX_RAM_SIZE/2)| BATL_PP_10 | BATL_MEMCOHERENCE));

	write_bat(DBAT1, ((CFG_MAX_RAM_SIZE/2) | BATU_BL_256M | BATU_VS | BATU_VP),
			( (CFG_MAX_RAM_SIZE/2)| BATL_PP_10 | BATL_MEMCOHERENCE));
*/
	for (i=0; i<SAVE_SZ; i++) {
		save[i] = 0;		/* clear table */
	}

	for (i=0, cnt=(CFG_MAX_RAM_SIZE / sizeof(long)) >> 1; cnt > 0; cnt >>= 1) {
		addr = (volatile ulong *)base + cnt;
		save[i++] = *addr;
		*addr = ~cnt;
	}

	addr = (volatile ulong *)base;
	save[i] = *addr;
	*addr = 0;

	if (*addr != 0) {
		*addr = save[i];
		goto Done;
	}

	for (cnt = 1; cnt < CFG_MAX_RAM_SIZE / sizeof(long); cnt <<= 1) {
		addr = (volatile ulong *)base + cnt;
		val = *addr;
		*addr = save[--i];
		if (val != ~cnt) {
			ulong new_bank0_end = cnt * sizeof(long) - 1;
			ulong mear1  = mpc824x_mpc107_getreg(MEAR1);
			ulong emear1 = mpc824x_mpc107_getreg(EMEAR1);
			mear1 =  (mear1  & 0xFFFFFF00) |
			  ((new_bank0_end & MICR_ADDR_MASK) >> MICR_ADDR_SHIFT);
			emear1 = (emear1 & 0xFFFFFF00) |
			  ((new_bank0_end & MICR_ADDR_MASK) >> MICR_EADDR_SHIFT);
			mpc824x_mpc107_setreg(MEAR1,  mear1);
			mpc824x_mpc107_setreg(EMEAR1, emear1);

			ret = cnt * sizeof(long);
			goto Done;
		}
	}

	ret = CFG_MAX_RAM_SIZE;
Done:
	return ret;
#else
	return (CFG_MAX_RAM_SIZE);
#endif

}


/*
 * Initialize PCI Devices, report devices found.
 */

static struct pci_config_table pci_utx8245_config_table[] = {
#ifndef CONFIG_PCI_PNP
	{ PCI_ANY_ID, PCI_ANY_ID, PCI_ANY_ID, PCI_ANY_ID, 0x0C, PCI_ANY_ID,
	  pci_cfgfunc_config_device, { PCI_ENET0_IOADDR,
				       PCI_ENET0_MEMADDR,
				       PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER }},
	{ PCI_ANY_ID, PCI_ANY_ID, PCI_ANY_ID, PCI_ANY_ID, 0x0B, PCI_ANY_ID,
	  pci_cfgfunc_config_device, { PCI_FIREWIRE_IOADDR,
				       PCI_FIREWIRE_MEMADDR,
				       PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER }},
#endif /*CONFIG_PCI_PNP*/
	{ }
};


static void pci_utx8245_fixup_irq(struct pci_controller *hose, pci_dev_t dev)
{
	if (PCI_DEV(dev) == 11)
		/* assign serial interrupt line 9 (int25) to FireWire */
		pci_hose_write_config_byte(hose, dev, PCI_INTERRUPT_LINE, 25);

	else if (PCI_DEV(dev) == 12)
		/* assign serial interrupt line 8 (int24) to Ethernet */
		pci_hose_write_config_byte(hose, dev, PCI_INTERRUPT_LINE, 24);

	else if (PCI_DEV(dev) == 14)
		/* assign serial interrupt line 0 (int16) to PMC slot 0 */
		pci_hose_write_config_byte(hose, dev, PCI_INTERRUPT_LINE, 16);

	else if (PCI_DEV(dev) == 15)
		/* assign serial interrupt line 1 (int17) to PMC slot 1 */
		pci_hose_write_config_byte(hose, dev, PCI_INTERRUPT_LINE, 17);
}

static struct pci_controller utx8245_hose = {
#ifndef CONFIG_PCI_PNP
	config_table: pci_utx8245_config_table,
	fixup_irq: pci_utx8245_fixup_irq,
	write_byte: pci_hose_write_config_byte
#endif /*CONFIG_PCI_PNP*/
};

void pci_init_board (void)
{
	pci_mpc824x_init(&utx8245_hose);

	icache_enable();
}
