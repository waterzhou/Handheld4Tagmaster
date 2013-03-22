#ifndef _PC104BUSIO_H
#define _PC104BUSIO_H
void *pc104bus_io_open(void);
void *pc104bus_mem_open(void);
int  pc104bus_io_close(void);
int  pc104bus_mem_close(void);
#endif