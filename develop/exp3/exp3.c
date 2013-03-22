#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define ULED1_CONTROL	1
#define ULED2_CONTROL	2
#define ULED3_CONTROL	3
#define ULED4_CONTROL	4

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
	
	databuf[0] = ULED1_CONTROL;
	databuf[1] = 1;
	write(fd, databuf, 2);

	databuf[0] = ULED2_CONTROL;
	databuf[1] = 0;
	write(fd, databuf, 2);

	led3 = 1;							
	led4 = 0;
	while(1){
		databuf[0] = ULED3_CONTROL;
		databuf[1] = led3;
		write(fd, databuf, 2);
	
		databuf[0] = ULED4_CONTROL;
		databuf[1] = led4;
		write(fd, databuf, 2);
	
		led3 = !led3;
		led4 = !led4;		
		sleep(1);
	}


	close(fd);
	exit(0);	
}
