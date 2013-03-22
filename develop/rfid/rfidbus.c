#include <stdio.h> 
#include <fcntl.h> 
#include <sys/mman.h> 

#define DEV_FILE "/dev/mmapdrv" 

#define SRAM_STARTADD 0x70000000 
#define SRAM_SIZE (0x400<<4) //16kB 
#define MMAP_SIZE (1*1024) 
#define IOMAP_WRITE1 1
#define IOMAP_WRITE2 2
#define IOMAP_READ1  3
#define IOMAP_READ2  4

int test(int fd ,int cmd,int data)
{
  if(ioctl(fd,cmd,(void *)&data)<0)
    {
      printf("ioctl failed\n");
      return -1;
    }
  return 0;
}

int main(int argc ,char **argv) 
{ 
  int fd; 
  int i; 
  if(argc<2)
    {
      return -1;
    }
  fd = open(DEV_FILE, O_RDWR); 
  if(!strcmp(argv[1], "-W1"))
    {
      test(fd,IOMAP_WRITE1,0);
    }
  else if(!strcmp(argv[1], "-W2"))
    {
      test(fd,IOMAP_WRITE2,0);
    }
  else if(!strcmp(argv[1], "-R1"))
    {
      test(fd,IOMAP_READ1,0);
    }
  else if(!strcmp(argv[1], "-R2"))
    {
      test(fd,IOMAP_READ2,0);
    }
  else if(!strcmp(argv[1], "-MMAP"))
    {
      unsigned short* vadr=NULL; 
      vadr = (short*)mmap(NULL, MMAP_SIZE, PROT_READ|PROT_WRITE , MAP_SHARED, fd, 0); 
      if (vadr == MAP_FAILED) 
        { 
	  perror("mmap"); 
	  exit(-1); 
        } 
      for(i=0;i<10;i++) 
        { 
	  *(unsigned short *)(vadr+i)=0xAA+i; 
        } 
      printf("\n"); 
      for(i=0;i<10;i++) 
        { 
	  printf("[0x%x]",*(unsigned short *)(vadr+i)); 
        } 
      printf("\n"); 
      munmap(vadr, MMAP_SIZE); 
    }else 
    {
      printf("error\n");
    }
  close(fd); 
  return 0; 
}
