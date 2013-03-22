/*
	2007-9-8 
	arm-pc104 io read & write function interface  
	VERSION 1.0.0
*/

#define MODE_8BIT  0
#define MODE_16BIT 1
#define MODE_32BIT 2
unsigned long *iobase; //IO BASE ADDRESS

#define inl(addr) *((unsigned long  *)(iobase) + (addr >> 2) )
#define inw(addr) *((unsigned short *)(iobase) + (addr >> 1) )
#define inb(addr) *((unsigned char  *)(iobase) + (addr))

#define outl(val,addr) *((unsigned long  *)(iobase) + (addr >> 2)) = val
#define outw(val,addr) *((unsigned short *)(iobase) + (addr >>1 )) = val
#define outb(val,addr) *((unsigned char  *)(iobase) + (addr))  = val

//#ifndef _PC104IO_H
//	#define _PC104IO_H   

int pc104_io_open(void);
int pc104_io_close(void);


//#endif
