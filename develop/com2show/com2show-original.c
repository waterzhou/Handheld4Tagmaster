/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>


const char *com2 = "/dev/ttyS1";
//const char *com2 = "/dev/ttyUSB0";

static struct termios newtios, oldtios;		/* terminal settings */
static int saved_portfd = -1;           /* serial port fd */

/* cleanup atexit handler */
static void reset_tty_atexit(void)
{
	if(saved_portfd != -1){
		tcsetattr(saved_portfd, TCSANOW, &oldtios);
	}
}

/* cleanup signal handler */
static void reset_tty_handler(int signal)
{
	if(saved_portfd != -1){
		tcsetattr(saved_portfd, TCSANOW, &oldtios);
	}
	_exit(EXIT_FAILURE);
}

static int open_port(const char *portname)
{
	struct sigaction sa;
	int portfd;

	printf("opening serial port: %s\n", portname);

	/* open serial port */
	if((portfd = open(portname, O_RDWR|O_NOCTTY)) < 0){
		printf("open serial port %s fail\n", portname);
		return portfd;
	}

	/* get serial port params, save away */
	tcgetattr(portfd, &newtios);
	memcpy(&oldtios, &newtios, sizeof newtios);

	
	/* 115200 bps */
	cfsetospeed(&newtios, B38400);
	cfsetispeed(&newtios, B38400);
	/*8*/
	newtios.c_cflag &= ~CSIZE;
	newtios.c_cflag |= CS8;
	/*N*/
    newtios.c_cflag &= ~PARENB;
    newtios.c_iflag &= ~(INPCK | ISTRIP);
	/*1*/
	newtios.c_cflag &= ~CSTOPB;
	newtios.c_cflag &= ~CRTSCTS;

    newtios.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG) ;      /* ignore parity on input */
	newtios.c_oflag &= ~OPOST;
	newtios.c_cflag |= (CLOCAL|CREAD);
	newtios.c_cc[VMIN] = 1;         /* block until 1 char received */
	newtios.c_cc[VTIME] = 5;     /* no inter-character timer*/
	
	/* register cleanup stuff  */
	atexit(reset_tty_atexit);
	memset(&sa, 0, sizeof sa);
	sa.sa_handler = reset_tty_handler;
	sigaction(SIGHUP, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGPIPE, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);

	/* apply modified termios */
	saved_portfd = portfd;
	tcflush(portfd, TCIFLUSH);
	tcsetattr(portfd, TCSADRAIN, &newtios);

	return portfd;
}

static void close_port(int portfd)
{
	tcsetattr(portfd, TCSANOW, &oldtios);
	close(portfd);
	saved_portfd = -1;
}

int main(int argc, char *argv[])
{
	fd_set fds;
	int portfd;
	int retval;
	unsigned char c;
	unsigned char Send_Buffer[13]={0xa5,0x5a,0x09,0x82,0x01,0x00,0x30,0x31,0x32,0x33,0x34,0x35};
	//static unsigned char Send_Buffer2[7]={0xAA,0xE0,0x55,0xAA,0x5A,0xA5,0x08,0x07};

	if((portfd = open_port(com2)) < 0)
		return -1;
    printf("zhoujz will write\n");
	if(write(portfd,Send_Buffer,13) < 0)
	  {
	    printf("zhoujz write error\r\n");
	    return -1;
	  }

	while(1){
		FD_ZERO(&fds);
		FD_SET(portfd, &fds);

		retval = select(portfd + 1, &fds, NULL, NULL, NULL);
		if(FD_ISSET(portfd, &fds)){
			if(read(portfd, &c, 1) == 1)
//			    			putchar(c);
			  printf("0x%x",c);
		}
		fflush(NULL);
	}
	
	return 0;
}
