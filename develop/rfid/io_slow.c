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
#
//#undef DEBUG
#define DEBUG

#define BAUDRATE B19200 
#define COM3 "/dev/ttyS3"  //for 8051 communication




#ifdef DEBUG
#define DPRINTF(str...) printf (str)
#else
#define DPRINTF(str...) /* nothing */
#endif

#define iotype unsigned short   



static void show_buf(char *buf,int len);
static int fd;
static iotype *iobase; //IO BASE ADDRESS
unsigned int d[2];
#define is_digit(c)	((c) >= '0' && (c) <= '9')

/*********************************************************************/
unsigned long simple_strtoul(const char *cp,char **endp,unsigned int base)
{
	unsigned long result = 0,value;

	if (*cp == '0') {
		cp++;
		if ((*cp == 'x') && isxdigit(cp[1])) {
			base = 16;
			cp++;
		}
		if (!base) {
			base = 8;
		}
	}
	if (!base) {
		base = 10;
	}
	while (isxdigit(*cp) && (value = isdigit(*cp) ? *cp-'0' : (islower(*cp)
			  ? toupper(*cp) : *cp)-'A'+10) < base) {
		result = result*base + value;
		cp++;
			  }
			  if (endp)
				  *endp = (char *)cp;
			  return result;
}
/*********************************************************************/
long simple_strtol(const char *cp,char **endp,unsigned int base)
{
	if(*cp=='-')
		return -simple_strtoul(cp+1,endp,base);
	return simple_strtoul(cp,endp,base);
}



/*********************************************************************/
int io_open(void)
{
	fd = open("/dev/armio",O_RDWR);
	if(fd < 0){
		printf("###open /dev/armio fail####\n");
		return (-1);
	}
	iobase = (iotype *)mmap(0, 4096,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
	return 0;
}
/*********************************************************************/
int io_close(void)
{
	return close(fd);
}
/*********************************************************************/
//  A0-A6  address: 0-->63
unsigned short inputw(unsigned int offset)
{
	unsigned int d[2];
	d[0] = offset;
	d[1] = 16;
	read(fd,d,8);
	return (unsigned short)d[1];
	//*(iobase+offset) = val;
	//return 0;
}
/*********************************************************************/
unsigned char inputb(unsigned int offset)
{
	unsigned int d[2];
	d[0] = offset;
	d[1] = 8;
	read(fd,d,8);
	return (unsigned char)d[1];
}

/*********************************************************************/
int outputw(unsigned int offset,unsigned short val)
{
	unsigned int d[2];
	d[0] = offset;
	d[1] = val+0x00100000; //16bit write
	return write(fd,d,8);
	//*(iobase+offset) = val;
	//return 0;
}


/*********************************************************************/
int  outputb(unsigned int offset,unsigned char val)
{
	unsigned int d[2];
	d[0] = offset;
	d[1] = val + 0x00080000; //8bit write
	return write(fd,d,8);
}

/*********************************************************************/
static void showhelp()
{
	printf("***********************************************\n\r");
	printf("Usage: io w address value [address: 0->63]\n\r");
	printf("       io r address       [address: 0->63]\n\r");
	printf("Example: io w 0x20 0x1234 ; io w 20 65535  \n\r");
	printf("         io r 0x30        ; io r 63 \n\r");
	printf("***********************************************\n\r");
	
}


int main(int argc, char **argv)
{
	void * retval;
	int fd;
	int i,j,k;
	int w_length=0;
	
	iotype val,addr;
//	unsigned short *iobase;
	
	if(argc<3){
		showhelp();
		exit(0);
	}

	fd=io_open();
	if(fd < 0){
		//printf("####io  device open fail####\n");
		return (-1);
	}
	if(strncmp(argv[1],"w",1)==0){
		if(argc < 4){
			showhelp();
			exit(0);
		}
		if(argv[3][1]=='x' ||argv[3][1]=='X'){
			val=simple_strtoul(argv[3],0,16);
		}else{
			val = atoi(argv[3]);
		}
		if(argv[2][1]=='x' ||argv[2][1]=='X'){
			addr = simple_strtoul(argv[2],0,16);;
		}else{
			addr = atoi(argv[2]);
		}

		printf("write address: 0x%x (%d) = 0x%x (%d)\n",addr,addr,val,val);
		if(argc == 5){
			while(1)outputw(addr,val);
		}else
			outputw(addr,val);
	}		
	if(strncmp(argv[1],"r",1)==0){
		if(argc < 3){
			showhelp();
			exit(0);
		}
		if(argv[2][1]=='x' ||argv[2][1]=='X'){
			addr = simple_strtoul(argv[2],0,16);;
		}else{
			addr = atoi(argv[2]);
		}
		if(argc==4){
			while(1){
				val = inputb(addr);				
				printf("Read address 0x%x (%d) = 0x%08x (%d) \n",addr,addr,val,val);
				usleep(1000000);
			}
		}else
			val = inputb(addr);
			printf("Read address 0x%x (%d) = 0x%08x (%d) (%d) \n",addr,addr,val,val ,val&0xffff);

	}		
	io_close();
	
}
