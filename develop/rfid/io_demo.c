/*
	This program is used for LPT2NET VER3.0 
	author: zou jian guo <zounix@126.com>
	date:   2004-10-20
	update: 2005-08-19
			2005-9-30  fpga test  added
	
	
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <linux/types.h>
#include <linux/string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/signal.h>
#include "pc104_io.h"
//#undef DEBUG
#define DEBUG

#ifdef DEBUG
#define DPRINTF(str...) printf (str)
#else
#define DPRINTF(str...) /* nothing */
#endif

static int  fd;

/*********************************************************************/
int io_8bit_test(unsigned long addr)
{
	unsigned char data_in, data_out;
	data_out = 0xaa ;
	printf("IO 8 bit read & write test...\r\n");
	ioctl(fd,MODE_8BIT,NULL);
	usleep(100000);
	printf("Write data 0xaa to address: %lx \r\n",addr);
	outb(data_out,addr);
	data_in = inb(addr);
	printf("Read data from address %lx = %x\r\n",addr,data_in);
	return 0;
}
/*********************************************************************/
int io_16bit_test(unsigned long addr)
{
	unsigned short data_in, data_out;
	data_out = 0xaabb ;
	printf("IO 16 bit read & write test...\r\n");
	ioctl(fd,MODE_16BIT,NULL);
	usleep(100000);
	printf("Write data 0xaabb to address: %lx \r\n",addr);
	outw(data_out,addr);
	data_in = inw(addr);
	printf("Read data from address %lx = %x\r\n",addr,data_in);
	return 0;
}
/*********************************************************************/
int main(int argc, char **argv)
{
	if( (fd=pc104_io_open()) < 0){
		return (-1);
	}
	
	io_8bit_test(0x300);
	sleep(1);
	io_16bit_test(0x300);
	
	pc104_io_close();
	
}

