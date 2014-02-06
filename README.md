handheld4tagmaster
==================

This is for tagmaster China new handheld platform.

u-boot

-make clean
-make at91rm9200dk_config
-make

After above, u-boot.bin and u-boot.in.gz will be generated.


Flash memory map overview:

   0 - 10000000 - bootloader
   1 - 10020000 - gzipped u-boot.bin image
   2 - 10040000 - u-boot's environment variables
   3 - 10060000 - Linux kernel
   4 - 101A0000 - jffs2 flashfs 

How to burn u-boot?

-115200 8N1 none
-xmodem download loader.bin
-xmodem download u-boot.bin
-protect off all
-erase all
-loadb 20000000(boot.bin--Kermit)
-cp.b 20000000 10000000 xxx
-loadb 20000000(u-boot.bin.gz---Kermit)
-cp.b 20000000 10020000 xxx
-protect on 10000000 1003ffff
