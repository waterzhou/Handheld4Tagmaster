/*
 * Copyright 2005 DENX Software Engineering
 * Wolfgang Denk <wd@denx.de>
 * Copyright 2004 Freescale Semiconductor.
 * (C) Copyright 2002,2003 Motorola,Inc.
 * Xianghua Xiao <X.Xiao@motorola.com>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * TQM8560 board configuration file
 *
 * Make sure you change the MAC address and other network params first,
 * search for CONFIG_ETHADDR, CONFIG_SERVERIP, etc in this file.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High Level Configuration Options */
#define CONFIG_BOOKE		1	/* BOOKE */
#define CONFIG_E500		1	/* BOOKE e500 family */
#define CONFIG_MPC85xx		1	/* MPC8540/MPC8560 */
#define CONFIG_CPM2		1	/* has CPM2 */
#define CONFIG_MPC8560		1	/* MPC8560 specific */
#define CONFIG_TQM8560		1	/* TQM8560 board specific */

/*
 * BIG FAT WARNING: Right now PCI seems to have a problem on the
 * TQM8560 on the Starter Kit. So, if the board doen't come up
 * please disable the PCI support for now. sr@denx.de, 15-09-2005
 */
#define CONFIG_PCI
#define CONFIG_TSEC_ENET		/* tsec ethernet support */
#undef CONFIG_DDR_ECC			/* only for ECC DDR module */
#define CONFIG_DDR_DLL			/* possible DLL fix needed */
#define CONFIG_DDR_2T_TIMING		/* Sets the 2T timing bit */

/*
 * sysclk for MPC85xx
 *
 * Two valid values are:
 *    33000000
 *    66000000
 *
 * Most PCI cards are still 33Mhz, so in the presence of PCI, 33MHz
 * is likely the desired value here, so that is now the default.
 * The board, however, can run at 66MHz.  In any event, this value
 * must match the settings of some switches.  Details can be found
 * in the README.mpc85xxads.
 */

#ifndef CONFIG_SYS_CLK_FREQ
#define CONFIG_SYS_CLK_FREQ	33333333
#endif

/*
 * These can be toggled for performance analysis, otherwise use default.
 */
#define CONFIG_L2_CACHE			/* toggle L2 cache */
#define CONFIG_BTB			/* toggle branch predition */
#define CONFIG_ADDR_STREAMING		/* toggle addr streaming */

#define CONFIG_BOARD_EARLY_INIT_F	1	/* Call board_pre_init */

#define CFG_INIT_DBCR DBCR_IDM		/* Enable Debug Exceptions */

#undef	CFG_DRAM_TEST			/* memory test, takes time */
#define CFG_MEMTEST_START	0x00000000	/* memtest region */
#define CFG_MEMTEST_END		0x10000000

/*
 * Base addresses -- Note these are effective addresses where the
 * actual resources get mapped (not physical addresses)
 */
#define CFG_CCSRBAR_DEFAULT	0xFF700000	/* CCSRBAR Default */
#define CFG_CCSRBAR		0xE0000000	/* relocated CCSRBAR */
#define CFG_IMMR		CFG_CCSRBAR	/* PQII uses CFG_IMMR */

/*
 * DDR Setup
 */
#define CFG_DDR_SDRAM_BASE	0x00000000	/* DDR is system memory*/
#define CFG_SDRAM_BASE		CFG_DDR_SDRAM_BASE

#if defined(CONFIG_SPD_EEPROM)
    /*
     * Determine DDR configuration from I2C interface.
     */
    #define SPD_EEPROM_ADDRESS	0x51		/* DDR DIMM */

#else
    /*
     * Manually set up DDR parameters
     */
    #define CFG_SDRAM_SIZE	512		/* DDR is 256MB */
    #define CFG_DDR_CS0_BNDS	0x0000001f	/* 0-256MB */
    #define CFG_DDR_CS0_CONFIG	0x80000102
    #define CFG_DDR_TIMING_1	0x47445331
    #define CFG_DDR_TIMING_2	0x00000800	/* P9-45,may need tuning */
    #define CFG_DDR_CONTROL	0xc2000000	/* unbuffered,no DYN_PWR */
    #define CFG_DDR_MODE	0x40020062	/* DLL,normal,seq,4/2.5 */
    #define CFG_DDR_INTERVAL	0x05160100	/* autocharge,no open page */
#endif

/*
 * Flash on the Local Bus
 */
#define CFG_LBC_FLASH_BASE	0xfe000000	/* Localbus SDRAM */
#define CFG_LBC_FLASH_SIZE	32		/* LBC SDRAM is 32MB */

#define CFG_FLASH_BASE		CFG_LBC_FLASH_BASE	/* start of FLASH 32M */
#define CFG_BR0_PRELIM		0xfe001801	/* port size 32bit */

#define CFG_OR0_PRELIM		0xfe000040	/* 32MB Flash */
#define CFG_MAX_FLASH_BANKS	1		/* number of banks */
#define CFG_MAX_FLASH_SECT	256		/* sectors per device */
#undef	CFG_FLASH_CHECKSUM
#define CFG_FLASH_ERASE_TOUT	60000	/* Flash Erase Timeout (ms) */
#define CFG_FLASH_WRITE_TOUT	500	/* Flash Write Timeout (ms) */

#define CFG_MONITOR_BASE	TEXT_BASE	/* start of monitor */

#if (CFG_MONITOR_BASE < CFG_FLASH_BASE)
#define CFG_RAMBOOT
#else
#undef	CFG_RAMBOOT
#endif

#define CFG_FLASH_CFI_DRIVER
#define CFG_FLASH_CFI
#define CFG_FLASH_EMPTY_INFO

#define CFG_LBC_LCRR		0x00030008    /* LB clock ratio reg */
#define CFG_LBC_LBCR		0x00000000    /* LB config reg */
#define CFG_LBC_LSRT		0x20000000    /* LB sdram refresh timer */
#define CFG_LBC_MRTPR		0x20000000    /* LB refresh timer prescal*/

/*
 * LSDMR masks
 */
#define CFG_LBC_LSDMR_RFEN	(1 << (31 -  1))
#define CFG_LBC_LSDMR_BSMA1516	(3 << (31 - 10))
#define CFG_LBC_LSDMR_BSMA1617	(4 << (31 - 10))
#define CFG_LBC_LSDMR_RFCR5	(3 << (31 - 16))
#define CFG_LBC_LSDMR_RFCR16	(7 << (31 - 16))
#define CFG_LBC_LSDMR_PRETOACT3 (3 << (31 - 19))
#define CFG_LBC_LSDMR_PRETOACT7 (7 << (31 - 19))
#define CFG_LBC_LSDMR_ACTTORW3	(3 << (31 - 22))
#define CFG_LBC_LSDMR_ACTTORW7	(7 << (31 - 22))
#define CFG_LBC_LSDMR_ACTTORW6	(6 << (31 - 22))
#define CFG_LBC_LSDMR_BL8	(1 << (31 - 23))
#define CFG_LBC_LSDMR_WRC2	(2 << (31 - 27))
#define CFG_LBC_LSDMR_WRC4	(0 << (31 - 27))
#define CFG_LBC_LSDMR_BUFCMD	(1 << (31 - 29))
#define CFG_LBC_LSDMR_CL3	(3 << (31 - 31))

#define CFG_LBC_LSDMR_OP_NORMAL (0 << (31 - 4))
#define CFG_LBC_LSDMR_OP_ARFRSH (1 << (31 - 4))
#define CFG_LBC_LSDMR_OP_SRFRSH (2 << (31 - 4))
#define CFG_LBC_LSDMR_OP_MRW	(3 << (31 - 4))
#define CFG_LBC_LSDMR_OP_PRECH	(4 << (31 - 4))
#define CFG_LBC_LSDMR_OP_PCHALL (5 << (31 - 4))
#define CFG_LBC_LSDMR_OP_ACTBNK (6 << (31 - 4))
#define CFG_LBC_LSDMR_OP_RWINV	(7 << (31 - 4))

#define CFG_LBC_LSDMR_COMMON	( CFG_LBC_LSDMR_BSMA1516	\
				| CFG_LBC_LSDMR_RFCR5		\
				| CFG_LBC_LSDMR_PRETOACT3	\
				| CFG_LBC_LSDMR_ACTTORW3	\
				| CFG_LBC_LSDMR_BL8		\
				| CFG_LBC_LSDMR_WRC2		\
				| CFG_LBC_LSDMR_CL3		\
				| CFG_LBC_LSDMR_RFEN		\
				)

/*
 * SDRAM Controller configuration sequence.
 */
#define CFG_LBC_LSDMR_1		( CFG_LBC_LSDMR_COMMON \
				| CFG_LBC_LSDMR_OP_PCHALL)
#define CFG_LBC_LSDMR_2		( CFG_LBC_LSDMR_COMMON \
				| CFG_LBC_LSDMR_OP_ARFRSH)
#define CFG_LBC_LSDMR_3		( CFG_LBC_LSDMR_COMMON \
				| CFG_LBC_LSDMR_OP_ARFRSH)
#define CFG_LBC_LSDMR_4		( CFG_LBC_LSDMR_COMMON \
				| CFG_LBC_LSDMR_OP_MRW)
#define CFG_LBC_LSDMR_5		( CFG_LBC_LSDMR_COMMON \
				| CFG_LBC_LSDMR_OP_NORMAL)

#define CONFIG_L1_INIT_RAM
#define CFG_INIT_RAM_LOCK	1
#define CFG_INIT_RAM_ADDR	0xe4010000	/* Initial RAM address */
#define CFG_INIT_RAM_END	0x4000		/* End of used area in RAM */

#define CFG_GBL_DATA_SIZE	128		/* num bytes initial data */
#define CFG_GBL_DATA_OFFSET	(CFG_INIT_RAM_END - CFG_GBL_DATA_SIZE)
#define CFG_INIT_SP_OFFSET	CFG_GBL_DATA_OFFSET

#define CFG_MONITOR_LEN		(256 * 1024)	/* Reserve 256 kB for Mon */
#define CFG_MALLOC_LEN		(128 * 1024)	/* Reserved for malloc */

/* Serial Port */
#define CONFIG_CONS_ON_SCC      /* define if console on SCC */
#undef  CONFIG_CONS_NONE        /* define if console on something else */
#define CONFIG_CONS_INDEX       1  /* which serial channel for console */

#define CONFIG_BAUDRATE         115200

#define CFG_BAUDRATE_TABLE  \
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400,115200}

/* Use the HUSH parser */
#define CFG_HUSH_PARSER
#ifdef	CFG_HUSH_PARSER
#define CFG_PROMPT_HUSH_PS2 "> "
#endif

/* I2C */
#define CONFIG_HARD_I2C			/* I2C with hardware support	*/
#undef	CONFIG_SOFT_I2C			/* I2C bit-banged		*/
#define CFG_I2C_SPEED		400000	/* I2C speed and slave address	*/
#define CFG_I2C_SLAVE		0x7F
#define CFG_I2C_NOPROBES	{0x48}	/* Don't probe these addrs	*/

/* I2C RTC */
#define CONFIG_RTC_DS1337		/* Use ds1337 rtc via i2c	*/
#define CFG_I2C_RTC_ADDR	0x68	/* at address 0x68		*/

/* I2C EEPROM */
/*
 * EEPROM configuration for onboard EEPROM M24C32 (M24C64 should work also).
 */
#define CFG_I2C_EEPROM_ADDR		0x50	/* 1010000x		*/
#define CFG_I2C_EEPROM_ADDR_LEN		2
#define CFG_EEPROM_PAGE_WRITE_BITS	5	/* =32 Bytes per write	*/
#define CFG_EEPROM_PAGE_WRITE_ENABLE
#define CFG_EEPROM_PAGE_WRITE_DELAY_MS	20
#define CFG_I2C_MULTI_EEPROMS		1       /* more than one eeprom */

/* I2C SYSMON (LM75) */
#define CONFIG_DTT_LM75		1		/* ON Semi's LM75	*/
#define CONFIG_DTT_SENSORS	{0}		/* Sensor addresses	*/
#define CFG_DTT_MAX_TEMP	70
#define CFG_DTT_LOW_TEMP	-30
#define CFG_DTT_HYSTERESIS	3

/* RapidIO MMU */
#define CFG_RIO_MEM_BASE	0xc0000000	/* base address */
#define CFG_RIO_MEM_PHYS	CFG_RIO_MEM_BASE
#define CFG_RIO_MEM_SIZE	0x20000000	/* 128M */

/*
 * General PCI
 * Addresses are mapped 1-1.
 */
#define CFG_PCI1_MEM_BASE	0x80000000
#define CFG_PCI1_MEM_PHYS	CFG_PCI1_MEM_BASE
#define CFG_PCI1_MEM_SIZE	0x20000000	/* 512M */
#define CFG_PCI1_IO_BASE	0xe2000000
#define CFG_PCI1_IO_PHYS	CFG_PCI1_IO_BASE
#define CFG_PCI1_IO_SIZE	0x1000000	/* 16M */

#if defined(CONFIG_PCI)

#define CONFIG_NET_MULTI
#define CONFIG_PCI_PNP			/* do pci plug-and-play */

#define CONFIG_EEPRO100
#undef CONFIG_TULIP

#if !defined(CONFIG_PCI_PNP)
    #define PCI_ENET0_IOADDR	0xe0000000
    #define PCI_ENET0_MEMADDR	0xe0000000
    #define PCI_IDSEL_NUMBER	0x0c	/* slot0->3(IDSEL)=12->15 */
#endif

#undef CONFIG_PCI_SCAN_SHOW		/* show pci devices on startup */
#define CFG_PCI_SUBSYS_VENDORID 0x1057	/* Motorola */

#endif	/* CONFIG_PCI */


#if defined(CONFIG_TSEC_ENET)

#ifndef CONFIG_NET_MULTI
#define CONFIG_NET_MULTI	1
#endif

#define CONFIG_MII		1	/* MII PHY management */
#define CONFIG_MPC85XX_TSEC1	1
#define CONFIG_MPC85XX_TSEC1_NAME	"TSEC0"
#define CONFIG_MPC85XX_TSEC2	1
#define CONFIG_MPC85XX_TSEC2_NAME	"TSEC1"
#define TSEC1_PHY_ADDR		2
#define TSEC2_PHY_ADDR		1
#define TSEC1_PHYIDX		0
#define TSEC2_PHYIDX		0

#define CONFIG_MPC85XX_FEC	1
#define CONFIG_MPC85XX_FEC_NAME	"FEC"
#define FEC_PHY_ADDR		3
#define FEC_PHYIDX		0

#define CONFIG_HAS_ETH1
#define CONFIG_HAS_ETH2

/* Options are TSEC[0-1], FEC */
#define CONFIG_ETHPRIME		"TSEC0"

#endif	/* CONFIG_TSEC_ENET */

#define CONFIG_ETHER_ON_FCC
#define CONFIG_ETHER_ON_FCC3
#define CFG_CMXFCR_MASK3      (CMXFCR_FC3 | CMXFCR_RF3CS_MSK | CMXFCR_TF3CS_MSK)
#define CFG_CMXFCR_VALUE3     (CMXFCR_RF3CS_CLK15 | CMXFCR_TF3CS_CLK14)
#define CFG_CPMFCR_RAMTYPE    0
#define CFG_FCC_PSMR          (FCC_PSMR_FDE | FCC_PSMR_LPB)

/*
 * Environment
 */
#ifndef CFG_RAMBOOT
  #define CFG_ENV_IS_IN_FLASH	1
  #define CFG_ENV_ADDR		(CFG_MONITOR_BASE - 0x20000)
  #define CFG_ENV_SECT_SIZE	0x20000 /* 128K(one sector) for env */
  #define CFG_ENV_SIZE		0x2000
  #define CFG_ENV_OFFSET_REDUND	(CFG_ENV_OFFSET-CFG_ENV_SECT_SIZE)
  #define CFG_ENV_SIZE_REDUND	(CFG_ENV_SIZE)
#else
  #define CFG_NO_FLASH		1	/* Flash is not usable now */
  #define CFG_ENV_IS_NOWHERE	1	/* Store ENV in memory only */
  #define CFG_ENV_ADDR		(CFG_MONITOR_BASE - 0x1000)
  #define CFG_ENV_SIZE		0x2000
#endif

#define CONFIG_LOADS_ECHO	1	/* echo on for serial download */
#define CFG_LOADS_BAUD_CHANGE	1	/* allow baudrate change */

#define	CONFIG_TIMESTAMP		/* Print image info with timestamp */

#if defined(CFG_RAMBOOT)
# define CONFIG_CMD_PRIV	(CONFIG_CMD_DFL & ~(CFG_CMD_ENV  | CFG_CMD_LOADS))
#else
# define CONFIG_CMD_PRIV       (CONFIG_CMD_DFL	| \
				CFG_CMD_DHCP	| \
				CFG_CMD_NFS	| \
				CFG_CMD_SNTP	)
#endif

#if defined(CONFIG_PCI)
# define ADD_PCI_CMD		(CFG_CMD_PCI)
#else
# define ADD_PCI_CMD		0
#endif

#define CONFIG_COMMANDS        (CONFIG_CMD_PRIV	| \
				ADD_PCI_CMD	| \
				CFG_CMD_I2C	| \
				CFG_CMD_DATE	| \
				CFG_CMD_EEPROM	| \
				CFG_CMD_DTT	| \
				CFG_CMD_MII	| \
				CFG_CMD_PING	)
#include <cmd_confdefs.h>

#undef CONFIG_WATCHDOG			/* watchdog disabled */

/*
 * Miscellaneous configurable options
 */
#define CFG_LONGHELP			/* undef to save memory */
#define CFG_LOAD_ADDR	0x2000000	/* default load address */
#define CFG_PROMPT	"=> "		/* Monitor Command Prompt */

#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
    #define CFG_CBSIZE	1024		/* Console I/O Buffer Size */
#else
    #define CFG_CBSIZE	256		/* Console I/O Buffer Size */
#endif

#define CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */
#define CFG_MAXARGS	16		/* max number of command args */
#define CFG_BARGSIZE	CFG_CBSIZE	/* Boot Argument Buffer Size */
#define CFG_HZ		1000		/* decrementer freq: 1ms ticks */

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 8 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CFG_BOOTMAPSZ	(8 << 20)	/* Initial Memory map for Linux*/

/* Cache Configuration */
#define CFG_DCACHE_SIZE		32768
#define CFG_CACHELINE_SIZE	32
#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CFG_CACHELINE_SHIFT	5	/*log base 2 of the above value*/
#endif

/*
 * Internal Definitions
 *
 * Boot Flags
 */
#define BOOTFLAG_COLD	0x01		/* Normal Power-On: Boot from FLASH */
#define BOOTFLAG_WARM	0x02		/* Software reboot */

#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	230400	/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	2	/* which serial port to use */
#endif


#define CONFIG_LOADADDR	 200000 /* default location for tftp and bootm */

#define CONFIG_BOOTDELAY 5	/* -1 disables auto-boot */

#define CONFIG_BAUDRATE 115200

#define CONFIG_PREBOOT	"echo;"	\
	"echo Type \"run flash_nfs\" to mount root filesystem over NFS;" \
	"echo"

#undef	CONFIG_BOOTARGS		/* the boot command will set bootargs */

#define	CONFIG_EXTRA_ENV_SETTINGS					\
	"netdev=eth0\0"							\
	"consdev=ttyS0\0"						\
	"nfsargs=setenv bootargs root=/dev/nfs rw "			\
		"nfsroot=$serverip:$rootpath\0"				\
	"ramargs=setenv bootargs root=/dev/ram rw\0"			\
	"addip=setenv bootargs $bootargs "				\
		"ip=$ipaddr:$serverip:$gatewayip:$netmask"		\
		":$hostname:$netdev:off panic=1\0"			\
	"addcons=setenv bootargs $bootargs "				\
		"console=$consdev,$baudrate\0"				\
	"flash_nfs=run nfsargs addip addcons;"				\
		"bootm $kernel_addr\0"					\
	"flash_self=run ramargs addip addcons;"				\
		"bootm $kernel_addr $ramdisk_addr\0"			\
	"net_nfs=tftp $loadaddr $bootfile;"				\
		"run nfsargs addip addcons;bootm\0"			\
	"rootpath=/opt/eldk/ppc_85xx\0"					\
	"bootfile=/tftpboot/tqm8560/uImage\0"				\
	"kernel_addr=FE000000\0"					\
	"ramdisk_addr=FE100000\0"					\
	"load=tftp 100000 /tftpboot/tqm8560/u-boot.bin\0"		\
	"update=protect off fffc0000 ffffffff;era fffc0000 ffffffff;"	\
		"cp.b 100000 fffc0000 40000;"			        \
		"setenv filesize;saveenv\0"				\
	"upd=run load;run update\0"					\
	""
#define CONFIG_BOOTCOMMAND	"run flash_self"

#endif	/* __CONFIG_H */
