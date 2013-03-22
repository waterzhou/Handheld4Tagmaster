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
#define is_digit(c)	((c) >= '0' && (c) <= '9')
static int  fd;

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

/*******************************************************************/
static void showhelp()
{
	printf("***********************************************\n\r");
	printf("Usage: io w address value \n\r");
	printf("       io r address       \n\r");
	printf("Example: io w 0x20 0x1234 ; io w 20 65535  \n\r");
	printf("         io r 0x30        ; io r 63 \n\r");
	printf("***********************************************\n\r");
	
}


int main(int argc, char **argv)
{
	void * retval;
	int i,j,k;
	int w_length=0;
	char buf[0x10000];
	
	unsigned long addr;
	unsigned long val;
	
	if(argc<3){
		showhelp();
		exit(0);
	}
	if( (fd=pc104_io_open()) < 0){
		return (-1);
	}
//	ioctl(fd,MODE_8BIT,NULL); //config bank to 8 bit mode
	ioctl(fd,MODE_16BIT,NULL); //config bank to 16 bit mode
	
	if(strncmp(argv[1],"w",1)==0){
		if(argc < 4){
			showhelp();
			exit(0);
		}
		if(argv[3][1]=='x' ||argv[3][1]=='X'){
			val=simple_strtoul(argv[3],0,16) ;
		}else{
			val = atoi(argv[3]) ;
		}
		if(argv[2][1]=='x' ||argv[2][1]=='X'){
			addr = simple_strtoul(argv[2],0,16);;
		}else{
			addr = atoi(argv[2]);
		}

		printf("write address: 0x%x (%d) = 0x%x (%d)\n",addr,addr,val,val);
		if(argc == 5){
			while(1)
				outw(val,addr);
		}else
			outw(val,addr);
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
				val = inw(addr);				
//				printf("Read address 0x%x (%d) = 0x%04x (%d) \n",addr,addr,val,val);
				printf("Read address 0x%x (%d) = 0x%08x (%d) \n",addr,addr,val,val);
				//usleep(1000000);
			}
		}else
			val = inw(addr);				
			printf("Read address 0x%x (%d) = 0x%08x (%d) \n",addr,addr,val,val);
	}		
	pc104_io_close();
	
}

