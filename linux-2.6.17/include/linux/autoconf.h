/*
 * Automatically generated C config: don't edit
 * Linux kernel version: .6.17
 * Fri Mar 22 16:39:37 2013
 */
#define AUTOCONF_INCLUDED
#define CONFIG_ARM 1
#define CONFIG_MMU 1
#define CONFIG_RWSEM_GENERIC_SPINLOCK 1
#define CONFIG_GENERIC_HWEIGHT 1
#define CONFIG_GENERIC_CALIBRATE_DELAY 1
#define CONFIG_VECTORS_BASE 0xffff0000

/*
 * Code maturity level options
 */
#define CONFIG_EXPERIMENTAL 1
#define CONFIG_BROKEN_ON_SMP 1
#define CONFIG_INIT_ENV_ARG_LIMIT 32

/*
 * General setup
 */
#define CONFIG_LOCALVERSION ""
#define CONFIG_LOCALVERSION_AUTO 1
#undef CONFIG_SWAP
#define CONFIG_SYSVIPC 1
#undef CONFIG_POSIX_MQUEUE
#undef CONFIG_BSD_PROCESS_ACCT
#define CONFIG_SYSCTL 1
#undef CONFIG_AUDIT
#undef CONFIG_IKCONFIG
#undef CONFIG_RELAY
#define CONFIG_INITRAMFS_SOURCE ""
#define CONFIG_UID16 1
#define CONFIG_CC_OPTIMIZE_FOR_SIZE 1
#undef CONFIG_EMBEDDED
#define CONFIG_KALLSYMS 1
#undef CONFIG_KALLSYMS_ALL
#undef CONFIG_KALLSYMS_EXTRA_PASS
#define CONFIG_HOTPLUG 1
#define CONFIG_PRINTK 1
#define CONFIG_BUG 1
#define CONFIG_ELF_CORE 1
#define CONFIG_BASE_FULL 1
#define CONFIG_FUTEX 1
#define CONFIG_EPOLL 1
#define CONFIG_SHMEM 1
#define CONFIG_SLAB 1
#undef CONFIG_TINY_SHMEM
#define CONFIG_BASE_SMALL 0
#undef CONFIG_SLOB
#define CONFIG_OBSOLETE_INTERMODULE 1

/*
 * Loadable module support
 */
#define CONFIG_MODULES 1
#define CONFIG_MODULE_UNLOAD 1
#undef CONFIG_MODULE_FORCE_UNLOAD
#undef CONFIG_MODVERSIONS
#undef CONFIG_MODULE_SRCVERSION_ALL
#define CONFIG_KMOD 1

/*
 * Block layer
 */
#undef CONFIG_BLK_DEV_IO_TRACE

/*
 * IO Schedulers
 */
#define CONFIG_IOSCHED_NOOP 1
#define CONFIG_IOSCHED_AS 1
#undef CONFIG_IOSCHED_DEADLINE
#undef CONFIG_IOSCHED_CFQ
#define CONFIG_DEFAULT_AS 1
#undef CONFIG_DEFAULT_DEADLINE
#undef CONFIG_DEFAULT_CFQ
#undef CONFIG_DEFAULT_NOOP
#define CONFIG_DEFAULT_IOSCHED "anticipatory"

/*
 * System Type
 */
#undef CONFIG_ARCH_CLPS7500
#undef CONFIG_ARCH_CLPS711X
#undef CONFIG_ARCH_CO285
#undef CONFIG_ARCH_EBSA110
#undef CONFIG_ARCH_EP93XX
#undef CONFIG_ARCH_FOOTBRIDGE
#undef CONFIG_ARCH_INTEGRATOR
#undef CONFIG_ARCH_IOP3XX
#undef CONFIG_ARCH_IXP4XX
#undef CONFIG_ARCH_IXP2000
#undef CONFIG_ARCH_IXP23XX
#undef CONFIG_ARCH_L7200
#undef CONFIG_ARCH_PXA
#undef CONFIG_ARCH_RPC
#undef CONFIG_ARCH_SA1100
#undef CONFIG_ARCH_S3C2410
#undef CONFIG_ARCH_SHARK
#undef CONFIG_ARCH_LH7A40X
#undef CONFIG_ARCH_OMAP
#undef CONFIG_ARCH_VERSATILE
#undef CONFIG_ARCH_REALVIEW
#undef CONFIG_ARCH_IMX
#undef CONFIG_ARCH_H720X
#undef CONFIG_ARCH_AAEC2000
#define CONFIG_ARCH_AT91 1

/*
 * Atmel AT91 System-on-Chip
 */
#define CONFIG_ARCH_AT91RM9200 1

/*
 * AT91RM9200 Board Type
 */
#define CONFIG_ARCH_AT91RM9200DK 1
#undef CONFIG_MACH_AT91RM9200EK
#undef CONFIG_MACH_CSB337
#undef CONFIG_MACH_CSB637
#undef CONFIG_MACH_CARMEVA
#undef CONFIG_MACH_KB9200
#undef CONFIG_MACH_ATEB9200
#undef CONFIG_MACH_KAFA
#undef CONFIG_ARCH_AT91SAM9261

/*
 * AT91 Feature Selections
 */
#define CONFIG_AT91_PROGRAMMABLE_CLOCKS 1

/*
 * Processor Type
 */
#define CONFIG_CPU_32 1
#define CONFIG_CPU_ARM920T 1
#define CONFIG_CPU_32v4 1
#define CONFIG_CPU_ABRT_EV4T 1
#define CONFIG_CPU_CACHE_V4WT 1
#define CONFIG_CPU_CACHE_VIVT 1
#define CONFIG_CPU_COPY_V4WB 1
#define CONFIG_CPU_TLB_V4WBI 1

/*
 * Processor Features
 */
#undef CONFIG_ARM_THUMB
#undef CONFIG_CPU_ICACHE_DISABLE
#undef CONFIG_CPU_DCACHE_DISABLE
#undef CONFIG_CPU_DCACHE_WRITETHROUGH

/*
 * Bus support
 */

/*
 * PCCARD (PCMCIA/CardBus) support
 */
#define CONFIG_PCCARD 1
#undef CONFIG_PCMCIA_DEBUG
#define CONFIG_PCMCIA 1
#define CONFIG_PCMCIA_LOAD_CIS 1
#define CONFIG_PCMCIA_IOCTL 1

/*
 * PC-card bridges
 */
#define CONFIG_AT91_CF 1

/*
 * Kernel Features
 */
#undef CONFIG_PREEMPT
#undef CONFIG_NO_IDLE_HZ
#define CONFIG_HZ 100
#undef CONFIG_AEABI
#undef CONFIG_ARCH_DISCONTIGMEM_ENABLE
#define CONFIG_SELECT_MEMORY_MODEL 1
#define CONFIG_FLATMEM_MANUAL 1
#undef CONFIG_DISCONTIGMEM_MANUAL
#undef CONFIG_SPARSEMEM_MANUAL
#define CONFIG_FLATMEM 1
#define CONFIG_FLAT_NODE_MEM_MAP 1
#undef CONFIG_SPARSEMEM_STATIC
#define CONFIG_SPLIT_PTLOCK_CPUS 4096
#define CONFIG_LEDS 1
#define CONFIG_LEDS_TIMER 1
#undef CONFIG_LEDS_CPU
#define CONFIG_ALIGNMENT_TRAP 1

/*
 * Boot options
 */
#define CONFIG_ZBOOT_ROM_TEXT 0x0
#define CONFIG_ZBOOT_ROM_BSS 0x0
#define CONFIG_CMDLINE "mem=64M console=ttyS0,115200 initrd=0x21000000,8000000 root=/dev/ram rw"
#undef CONFIG_XIP_KERNEL

/*
 * Floating point emulation
 */

/*
 * At least one emulation must be selected
 */
#define CONFIG_FPE_NWFPE 1
#undef CONFIG_FPE_NWFPE_XP
#undef CONFIG_FPE_FASTFPE

/*
 * Userspace binary formats
 */
#define CONFIG_BINFMT_ELF 1
#undef CONFIG_BINFMT_AOUT
#undef CONFIG_BINFMT_MISC
#undef CONFIG_ARTHUR

/*
 * Power management options
 */
#undef CONFIG_PM
#undef CONFIG_APM

/*
 * Networking
 */
#define CONFIG_NET 1

/*
 * Networking options
 */
#undef CONFIG_NETDEBUG
#define CONFIG_PACKET 1
#undef CONFIG_PACKET_MMAP
#define CONFIG_UNIX 1
#undef CONFIG_NET_KEY
#define CONFIG_INET 1
#undef CONFIG_IP_MULTICAST
#undef CONFIG_IP_ADVANCED_ROUTER
#define CONFIG_IP_FIB_HASH 1
#define CONFIG_IP_PNP 1
#undef CONFIG_IP_PNP_DHCP
#define CONFIG_IP_PNP_BOOTP 1
#undef CONFIG_IP_PNP_RARP
#undef CONFIG_NET_IPIP
#undef CONFIG_NET_IPGRE
#undef CONFIG_ARPD
#undef CONFIG_SYN_COOKIES
#undef CONFIG_INET_AH
#undef CONFIG_INET_ESP
#undef CONFIG_INET_IPCOMP
#undef CONFIG_INET_XFRM_TUNNEL
#undef CONFIG_INET_TUNNEL
#define CONFIG_INET_DIAG 1
#define CONFIG_INET_TCP_DIAG 1
#undef CONFIG_TCP_CONG_ADVANCED
#define CONFIG_TCP_CONG_BIC 1
#undef CONFIG_IPV6
#undef CONFIG_INET6_XFRM_TUNNEL
#undef CONFIG_INET6_TUNNEL
#undef CONFIG_NETFILTER

/*
 * DCCP Configuration (EXPERIMENTAL)
 */
#undef CONFIG_IP_DCCP

/*
 * SCTP Configuration (EXPERIMENTAL)
 */
#undef CONFIG_IP_SCTP

/*
 * TIPC Configuration (EXPERIMENTAL)
 */
#undef CONFIG_TIPC
#undef CONFIG_ATM
#undef CONFIG_BRIDGE
#undef CONFIG_VLAN_8021Q
#undef CONFIG_DECNET
#undef CONFIG_LLC2
#undef CONFIG_IPX
#undef CONFIG_ATALK
#undef CONFIG_X25
#undef CONFIG_LAPB
#undef CONFIG_NET_DIVERT
#undef CONFIG_ECONET
#undef CONFIG_WAN_ROUTER

/*
 * QoS and/or fair queueing
 */
#undef CONFIG_NET_SCHED

/*
 * Network testing
 */
#undef CONFIG_NET_PKTGEN
#undef CONFIG_HAMRADIO
#undef CONFIG_IRDA
#undef CONFIG_BT
#undef CONFIG_IEEE80211

/*
 * Device Drivers
 */

/*
 * Generic Driver Options
 */
#define CONFIG_STANDALONE 1
#define CONFIG_PREVENT_FIRMWARE_BUILD 1
#define CONFIG_FW_LOADER 1
#undef CONFIG_DEBUG_DRIVER

/*
 * Connector - unified userspace <-> kernelspace linker
 */
#undef CONFIG_CONNECTOR

/*
 * Memory Technology Devices (MTD)
 */
#define CONFIG_MTD 1
#undef CONFIG_MTD_DEBUG
#undef CONFIG_MTD_CONCAT
#define CONFIG_MTD_PARTITIONS 1
#undef CONFIG_MTD_REDBOOT_PARTS
#define CONFIG_MTD_CMDLINE_PARTS 1
#undef CONFIG_MTD_AFS_PARTS

/*
 * User Modules And Translation Layers
 */
#define CONFIG_MTD_CHAR 1
#define CONFIG_MTD_BLOCK 1
#undef CONFIG_FTL
#undef CONFIG_NFTL
#undef CONFIG_INFTL
#undef CONFIG_RFD_FTL

/*
 * RAM/ROM/Flash chip drivers
 */
#define CONFIG_MTD_CFI 1
#define CONFIG_MTD_JEDECPROBE 1
#define CONFIG_MTD_GEN_PROBE 1
#undef CONFIG_MTD_CFI_ADV_OPTIONS
#define CONFIG_MTD_MAP_BANK_WIDTH_1 1
#define CONFIG_MTD_MAP_BANK_WIDTH_2 1
#define CONFIG_MTD_MAP_BANK_WIDTH_4 1
#undef CONFIG_MTD_MAP_BANK_WIDTH_8
#undef CONFIG_MTD_MAP_BANK_WIDTH_16
#undef CONFIG_MTD_MAP_BANK_WIDTH_32
#define CONFIG_MTD_CFI_I1 1
#define CONFIG_MTD_CFI_I2 1
#undef CONFIG_MTD_CFI_I4
#undef CONFIG_MTD_CFI_I8
#undef CONFIG_MTD_CFI_INTELEXT
#define CONFIG_MTD_CFI_AMDSTD 1
#undef CONFIG_MTD_CFI_STAA
#define CONFIG_MTD_CFI_UTIL 1
#undef CONFIG_MTD_RAM
#undef CONFIG_MTD_ROM
#undef CONFIG_MTD_ABSENT
#undef CONFIG_MTD_OBSOLETE_CHIPS

/*
 * Mapping drivers for chip access
 */
#undef CONFIG_MTD_COMPLEX_MAPPINGS
#define CONFIG_MTD_PHYSMAP 1
#define CONFIG_MTD_PHYSMAP_START 0x10000000
#define CONFIG_MTD_PHYSMAP_LEN 0x200000
#define CONFIG_MTD_PHYSMAP_BANKWIDTH 2
#undef CONFIG_MTD_ARM_INTEGRATOR
#undef CONFIG_MTD_IMPA7
#undef CONFIG_MTD_PLATRAM

/*
 * Self-contained MTD device drivers
 */
#undef CONFIG_MTD_SLRAM
#undef CONFIG_MTD_PHRAM
#undef CONFIG_MTD_MTDRAM
#undef CONFIG_MTD_BLOCK2MTD

/*
 * Disk-On-Chip Device Drivers
 */
#undef CONFIG_MTD_DOC2000
#undef CONFIG_MTD_DOC2001
#undef CONFIG_MTD_DOC2001PLUS
#define CONFIG_MTD_AT91_DATAFLASH 1
#undef CONFIG_MTD_AT91_DATAFLASH_CARD

/*
 * NAND Flash Device Drivers
 */
#undef CONFIG_MTD_NAND

/*
 * OneNAND Flash Device Drivers
 */
#undef CONFIG_MTD_ONENAND

/*
 * Parallel port support
 */
#undef CONFIG_PARPORT

/*
 * Plug and Play support
 */

/*
 * Block devices
 */
#undef CONFIG_BLK_DEV_COW_COMMON
#undef CONFIG_BLK_DEV_LOOP
#undef CONFIG_BLK_DEV_NBD
#define CONFIG_BLK_DEV_RAM 1
#define CONFIG_BLK_DEV_RAM_COUNT 16
#define CONFIG_BLK_DEV_RAM_SIZE 8192
#define CONFIG_BLK_DEV_INITRD 1
#undef CONFIG_CDROM_PKTCDVD
#undef CONFIG_ATA_OVER_ETH

/*
 * ATA/ATAPI/MFM/RLL support
 */
#undef CONFIG_IDE

/*
 * SCSI device support
 */
#undef CONFIG_RAID_ATTRS
#undef CONFIG_SCSI

/*
 * Multi-device support (RAID and LVM)
 */
#undef CONFIG_MD

/*
 * Fusion MPT device support
 */
#undef CONFIG_FUSION

/*
 * IEEE 1394 (FireWire) support
 */

/*
 * I2O device support
 */

/*
 * Network device support
 */
#define CONFIG_NETDEVICES 1
#undef CONFIG_DUMMY
#undef CONFIG_BONDING
#undef CONFIG_EQUALIZER
#undef CONFIG_TUN

/*
 * PHY device support
 */
#undef CONFIG_PHYLIB

/*
 * Ethernet (10 or 100Mbit)
 */
#define CONFIG_NET_ETHERNET 1
#define CONFIG_MII 1
#define CONFIG_ARM_AT91_ETHER 1
#undef CONFIG_SMC91X
#undef CONFIG_DM9000

/*
 * Ethernet (1000 Mbit)
 */

/*
 * Ethernet (10000 Mbit)
 */

/*
 * Token Ring devices
 */

/*
 * Wireless LAN (non-hamradio)
 */
#undef CONFIG_NET_RADIO

/*
 * PCMCIA network device support
 */
#undef CONFIG_NET_PCMCIA

/*
 * Wan interfaces
 */
#undef CONFIG_WAN
#undef CONFIG_PPP
#undef CONFIG_SLIP
#undef CONFIG_SHAPER
#undef CONFIG_NETCONSOLE
#undef CONFIG_NETPOLL
#undef CONFIG_NET_POLL_CONTROLLER

/*
 * ISDN subsystem
 */
#undef CONFIG_ISDN

/*
 * Input device support
 */
#define CONFIG_INPUT 1

/*
 * Userland interfaces
 */
#define CONFIG_INPUT_MOUSEDEV 1
#undef CONFIG_INPUT_MOUSEDEV_PSAUX
#define CONFIG_INPUT_MOUSEDEV_SCREEN_X 1024
#define CONFIG_INPUT_MOUSEDEV_SCREEN_Y 768
#undef CONFIG_INPUT_JOYDEV
#undef CONFIG_INPUT_TSDEV
#undef CONFIG_INPUT_EVDEV
#undef CONFIG_INPUT_EVBUG

/*
 * Input Device Drivers
 */
#undef CONFIG_INPUT_KEYBOARD
#undef CONFIG_INPUT_MOUSE
#undef CONFIG_INPUT_JOYSTICK
#undef CONFIG_INPUT_TOUCHSCREEN
#undef CONFIG_INPUT_MISC

/*
 * Hardware I/O ports
 */
#undef CONFIG_SERIO
#undef CONFIG_GAMEPORT

/*
 * Character devices
 */
#define CONFIG_VT 1
#define CONFIG_VT_CONSOLE 1
#define CONFIG_HW_CONSOLE 1
#undef CONFIG_SERIAL_NONSTANDARD

/*
 * Serial drivers
 */
#undef CONFIG_SERIAL_8250

/*
 * Non-8250 serial port support
 */
#define CONFIG_SERIAL_AT91 1
#define CONFIG_SERIAL_AT91_CONSOLE 1
#undef CONFIG_SERIAL_AT91_TTYAT
#define CONFIG_SERIAL_CORE 1
#define CONFIG_SERIAL_CORE_CONSOLE 1
#define CONFIG_UNIX98_PTYS 1
#define CONFIG_LEGACY_PTYS 1
#define CONFIG_LEGACY_PTY_COUNT 256

/*
 * IPMI
 */
#undef CONFIG_IPMI_HANDLER

/*
 * Watchdog Cards
 */
#define CONFIG_WATCHDOG 1
#define CONFIG_WATCHDOG_NOWAYOUT 1

/*
 * Watchdog Device Drivers
 */
#undef CONFIG_SOFT_WATCHDOG
#define CONFIG_AT91_WATCHDOG 1
#undef CONFIG_NVRAM
#undef CONFIG_DTLK
#undef CONFIG_R3964

/*
 * Ftape, the floppy tape device driver
 */

/*
 * PCMCIA character devices
 */
#undef CONFIG_SYNCLINK_CS
#undef CONFIG_CARDMAN_4000
#undef CONFIG_CARDMAN_4040
#undef CONFIG_RAW_DRIVER

/*
 * TPM devices
 */
#undef CONFIG_TCG_TPM
#undef CONFIG_TELCLOCK
#define CONFIG_AT91_SPI 1
#define CONFIG_AT91_SPIDEV 1

/*
 * I2C support
 */
#define CONFIG_I2C 1
#define CONFIG_I2C_CHARDEV 1

/*
 * I2C Algorithms
 */
#undef CONFIG_I2C_ALGOBIT
#undef CONFIG_I2C_ALGOPCF
#undef CONFIG_I2C_ALGOPCA

/*
 * I2C Hardware Bus support
 */
#define CONFIG_I2C_AT91 1
#undef CONFIG_I2C_PARPORT_LIGHT
#undef CONFIG_I2C_STUB
#undef CONFIG_I2C_PCA_ISA

/*
 * Miscellaneous I2C Chip support
 */
#undef CONFIG_SENSORS_DS1337
#undef CONFIG_SENSORS_DS1374
#undef CONFIG_SENSORS_EEPROM
#undef CONFIG_SENSORS_PCF8574
#undef CONFIG_SENSORS_PCA9539
#undef CONFIG_SENSORS_PCF8591
#undef CONFIG_SENSORS_MAX6875
#undef CONFIG_I2C_DEBUG_CORE
#undef CONFIG_I2C_DEBUG_ALGO
#undef CONFIG_I2C_DEBUG_BUS
#undef CONFIG_I2C_DEBUG_CHIP

/*
 * SPI support
 */
#undef CONFIG_SPI
#undef CONFIG_SPI_MASTER

/*
 * Dallas's 1-wire bus
 */
#undef CONFIG_W1

/*
 * Hardware Monitoring support
 */
#define CONFIG_HWMON 1
#undef CONFIG_HWMON_VID
#undef CONFIG_SENSORS_ADM1021
#undef CONFIG_SENSORS_ADM1025
#undef CONFIG_SENSORS_ADM1026
#undef CONFIG_SENSORS_ADM1031
#undef CONFIG_SENSORS_ADM9240
#undef CONFIG_SENSORS_ASB100
#undef CONFIG_SENSORS_ATXP1
#undef CONFIG_SENSORS_DS1621
#undef CONFIG_SENSORS_F71805F
#undef CONFIG_SENSORS_FSCHER
#undef CONFIG_SENSORS_FSCPOS
#undef CONFIG_SENSORS_GL518SM
#undef CONFIG_SENSORS_GL520SM
#undef CONFIG_SENSORS_IT87
#undef CONFIG_SENSORS_LM63
#undef CONFIG_SENSORS_LM75
#undef CONFIG_SENSORS_LM77
#undef CONFIG_SENSORS_LM78
#undef CONFIG_SENSORS_LM80
#undef CONFIG_SENSORS_LM83
#undef CONFIG_SENSORS_LM85
#undef CONFIG_SENSORS_LM87
#undef CONFIG_SENSORS_LM90
#undef CONFIG_SENSORS_LM92
#undef CONFIG_SENSORS_MAX1619
#undef CONFIG_SENSORS_PC87360
#undef CONFIG_SENSORS_SMSC47M1
#undef CONFIG_SENSORS_SMSC47B397
#undef CONFIG_SENSORS_W83781D
#undef CONFIG_SENSORS_W83792D
#undef CONFIG_SENSORS_W83L785TS
#undef CONFIG_SENSORS_W83627HF
#undef CONFIG_SENSORS_W83627EHF
#undef CONFIG_HWMON_DEBUG_CHIP

/*
 * Misc devices
 */

/*
 * LED devices
 */
#undef CONFIG_NEW_LEDS

/*
 * LED drivers
 */

/*
 * LED Triggers
 */

/*
 * Multimedia devices
 */
#undef CONFIG_VIDEO_DEV
#define CONFIG_VIDEO_V4L2 1

/*
 * Digital Video Broadcasting Devices
 */
#undef CONFIG_DVB

/*
 * Graphics support
 */
#undef CONFIG_FB

/*
 * Console display driver support
 */
#undef CONFIG_VGA_CONSOLE
#define CONFIG_DUMMY_CONSOLE 1

/*
 * Sound
 */
#undef CONFIG_SOUND

/*
 * USB support
 */
#define CONFIG_USB_ARCH_HAS_HCD 1
#define CONFIG_USB_ARCH_HAS_OHCI 1
#undef CONFIG_USB_ARCH_HAS_EHCI
#undef CONFIG_USB

/*
 * NOTE: USB_STORAGE enables SCSI, and 'SCSI disk support'
 */

/*
 * USB Gadget Support
 */
#define CONFIG_USB_GADGET 1
#undef CONFIG_USB_GADGET_DEBUG_FILES
#define CONFIG_USB_GADGET_SELECTED 1
#undef CONFIG_USB_GADGET_NET2280
#undef CONFIG_USB_GADGET_PXA2XX
#undef CONFIG_USB_GADGET_GOKU
#undef CONFIG_USB_GADGET_LH7A40X
#undef CONFIG_USB_GADGET_OMAP
#define CONFIG_USB_GADGET_AT91 1
#define CONFIG_USB_AT91 1
#undef CONFIG_USB_GADGET_DUMMY_HCD
#undef CONFIG_USB_GADGET_DUALSPEED
#undef CONFIG_USB_ZERO
#undef CONFIG_USB_ETH
#undef CONFIG_USB_GADGETFS
#undef CONFIG_USB_FILE_STORAGE
#undef CONFIG_USB_G_SERIAL

/*
 * MMC/SD Card support
 */
#define CONFIG_MMC 1
#undef CONFIG_MMC_DEBUG
#define CONFIG_MMC_BLOCK 1
#define CONFIG_MMC_AT91RM9200 1

/*
 * Real Time Clock
 */
#define CONFIG_RTC_LIB 1
#define CONFIG_RTC_CLASS 1
#undef CONFIG_RTC_HCTOSYS

/*
 * RTC interfaces
 */
#define CONFIG_RTC_INTF_SYSFS 1
#define CONFIG_RTC_INTF_PROC 1
#define CONFIG_RTC_INTF_DEV 1

/*
 * RTC drivers
 */
#undef CONFIG_RTC_DRV_X1205
#undef CONFIG_RTC_DRV_DS1672
#undef CONFIG_RTC_DRV_PCF8563
#undef CONFIG_RTC_DRV_RS5C372
#undef CONFIG_RTC_DRV_M48T86
#define CONFIG_RTC_DRV_AT91 1
#undef CONFIG_RTC_DRV_TEST

/*
 * File systems
 */
#define CONFIG_EXT2_FS 1
#undef CONFIG_EXT2_FS_XATTR
#undef CONFIG_EXT2_FS_XIP
#undef CONFIG_EXT3_FS
#undef CONFIG_REISERFS_FS
#undef CONFIG_JFS_FS
#undef CONFIG_FS_POSIX_ACL
#undef CONFIG_XFS_FS
#undef CONFIG_OCFS2_FS
#undef CONFIG_MINIX_FS
#undef CONFIG_ROMFS_FS
#define CONFIG_INOTIFY 1
#undef CONFIG_QUOTA
#define CONFIG_DNOTIFY 1
#undef CONFIG_AUTOFS_FS
#undef CONFIG_AUTOFS4_FS
#undef CONFIG_FUSE_FS

/*
 * CD-ROM/DVD Filesystems
 */
#undef CONFIG_ISO9660_FS
#undef CONFIG_UDF_FS

/*
 * DOS/FAT/NT Filesystems
 */
#undef CONFIG_MSDOS_FS
#undef CONFIG_VFAT_FS
#undef CONFIG_NTFS_FS

/*
 * Pseudo filesystems
 */
#define CONFIG_PROC_FS 1
#define CONFIG_SYSFS 1
#define CONFIG_TMPFS 1
#undef CONFIG_HUGETLB_PAGE
#define CONFIG_RAMFS 1
#undef CONFIG_CONFIGFS_FS

/*
 * Miscellaneous filesystems
 */
#undef CONFIG_ADFS_FS
#undef CONFIG_AFFS_FS
#undef CONFIG_HFS_FS
#undef CONFIG_HFSPLUS_FS
#undef CONFIG_BEFS_FS
#undef CONFIG_BFS_FS
#undef CONFIG_EFS_FS
#undef CONFIG_JFFS_FS
#undef CONFIG_JFFS2_FS
#define CONFIG_CRAMFS 1
#undef CONFIG_VXFS_FS
#undef CONFIG_HPFS_FS
#undef CONFIG_QNX4FS_FS
#undef CONFIG_SYSV_FS
#undef CONFIG_UFS_FS

/*
 * Network File Systems
 */
#undef CONFIG_NFS_FS
#undef CONFIG_NFSD
#undef CONFIG_SMB_FS
#undef CONFIG_CIFS
#undef CONFIG_NCP_FS
#undef CONFIG_CODA_FS
#undef CONFIG_AFS_FS
#undef CONFIG_9P_FS

/*
 * Partition Types
 */
#undef CONFIG_PARTITION_ADVANCED
#define CONFIG_MSDOS_PARTITION 1

/*
 * Native Language Support
 */
#undef CONFIG_NLS

/*
 * Profiling support
 */
#undef CONFIG_PROFILING

/*
 * Kernel hacking
 */
#undef CONFIG_PRINTK_TIME
#undef CONFIG_MAGIC_SYSRQ
#define CONFIG_DEBUG_KERNEL 1
#define CONFIG_LOG_BUF_SHIFT 14
#define CONFIG_DETECT_SOFTLOCKUP 1
#undef CONFIG_SCHEDSTATS
#undef CONFIG_DEBUG_SLAB
#undef CONFIG_DEBUG_MUTEXES
#undef CONFIG_DEBUG_SPINLOCK
#undef CONFIG_DEBUG_SPINLOCK_SLEEP
#undef CONFIG_DEBUG_KOBJECT
#define CONFIG_DEBUG_BUGVERBOSE 1
#undef CONFIG_DEBUG_INFO
#undef CONFIG_DEBUG_FS
#undef CONFIG_DEBUG_VM
#define CONFIG_FRAME_POINTER 1
#undef CONFIG_UNWIND_INFO
#define CONFIG_FORCED_INLINING 1
#undef CONFIG_RCU_TORTURE_TEST
#define CONFIG_DEBUG_USER 1
#undef CONFIG_DEBUG_WAITQ
#undef CONFIG_DEBUG_ERRORS
#define CONFIG_DEBUG_LL 1
#undef CONFIG_DEBUG_ICEDCC

/*
 * Security options
 */
#undef CONFIG_KEYS
#undef CONFIG_SECURITY

/*
 * Cryptographic options
 */
#undef CONFIG_CRYPTO

/*
 * Hardware crypto devices
 */

/*
 * Library routines
 */
#undef CONFIG_CRC_CCITT
#undef CONFIG_CRC16
#define CONFIG_CRC32 1
#undef CONFIG_LIBCRC32C
#define CONFIG_ZLIB_INFLATE 1
