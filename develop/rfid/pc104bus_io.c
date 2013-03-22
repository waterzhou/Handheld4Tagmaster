/*
  pc104 bus io and mem read&write interface function	
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <linux/types.h>
#include <linux/string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
static int fd,fd2;

/*********************************************************************/
void *pc104bus_io_open(void)
{
	void *iobase;
	fd = open("/dev/pc104_io/0",O_RDWR);
	if(fd < 0){
		printf("###open /dev/pc104_io/0 fail####\n");
		return (void *)(-1);
	}
	iobase = mmap(0, 0x1000000,PROT_READ | PROT_WRITE,  MAP_SHARED,fd,0);
	if(iobase == (void *)-1)return (void *)-1;
	printf("iobase = %lx \n",iobase);
	return iobase;
}

/*********************************************************************/
void *pc104bus_mem_open(void)
{
	void *iobase;
	fd2 = open("/dev/pc104_mem/0",O_RDWR);
	if(fd2 < 0){
		printf("###open /dev/pc104_mem/0 fail####\n");
		return (void *)(-1);
	}
	iobase = mmap(0, 0x1000000,PROT_READ | PROT_WRITE,  MAP_SHARED,fd,0);
	if(iobase == (void *)-1)return (void *)-1;
	printf("iobase = %lx \n",iobase);
	return iobase;
}
/*********************************************************************/
int pc104bus_io_close(void)
{
	return close(fd);
}
/*********************************************************************/
int pc104bus_mem_close(void)
{
	return close(fd2);
}
