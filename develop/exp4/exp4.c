#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define ULED1_CONTROL	1
#define ULED2_CONTROL	2
#define ULED3_CONTROL	3
#define ULED4_CONTROL	4
#define ZLG_CMD			5
#define ZLG_CMD_DATA	6

int main(int argc, char **argv)
{
	int fd;
	unsigned char databuf[50];
	unsigned char led3, led4;

	fd = open("/dev/zlg7289", O_RDWR);
	if(fd == -1){
		printf("open /dev/zlg7289 failed\n");
		exit(1);
	}
	
	databuf[0] = ZLG_CMD;
	databuf[1] = 0xa4;
	write(fd, databuf, 2);

	databuf[0] = ZLG_CMD_DATA;	
	databuf[1] = 0x80;	
	databuf[2] = 0x08;
	write(fd, databuf, 3);

	databuf[0] = ZLG_CMD_DATA;	
	databuf[1] = 0x85;	
	databuf[2] = 0x03;
	write(fd, databuf, 3);

	databuf[0] = ZLG_CMD;	
	databuf[1] = 0xa3;	
	while(1){
		sleep(1);
		write(fd, databuf, 2);
	}

	close(fd);
	exit(0);	
}
