#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	unsigned char databuf[50];
	int i;

	fd = open("/dev/zlg7289", O_RDWR);
	if(fd == -1){
		printf("open /dev/zlg7289 failed\n");
		exit(1);
	}
	
	//for(i=0; i<=100; i++){
	//	usleep(10000);
		
		databuf[0] = 0xa4;
		write(fd, databuf, 1);
		//sleep(1)
	
		databuf[0] = 0x80;
		databuf[1] = 0x05;
		write(fd, databuf, 2);
		
		databuf[0] = 0x84;
		databuf[1] = 0x03;
		write(fd, databuf, 2);
		databuf[0] = 0xa2;
		while(1){

		write(fd, databuf, 1);
		sleep(1);
}
		read(fd, databuf, 1);
						
//		*databuf = 0xbf;
//		write(fd, databuf, 1);
	//}

	close(fd);
	exit(0);	
}
