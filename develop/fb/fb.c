#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#include "font_8x8.c"

#define FONT_H  8
#define FONT_W  8

#define BLANK	0

#if 0
static unsigned char font[4096] = {
	/* BLANK */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	
	/**/
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,	
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	
};
#endif

static void showfont(char* screen_mm, int screen_h, int screen_w, int xres, int yres, unsigned char* font, int xscale, int yscale)
{
	int show_res = 0, font_res = 0;
	int i,j,k;
	unsigned char bit;
	
	for(i=0; i< FONT_H * yscale; i++){
		show_res = (yres+i) * screen_w + xres;
		if(yres+i >= screen_h)
			show_res -= screen_h * screen_w;
	
		font_res = i/yscale;
		bit = 0x80;	
		for(j=0; j<FONT_W; j++){
			for(k=0; k<xscale; k++){
				if(font[font_res] & bit)
					screen_mm[show_res] = 0xff;
				else
					screen_mm[show_res] = 0x00;
				show_res ++;
				if(show_res%screen_w==0)
					show_res -= screen_w;
			}//end t1
			bit = bit >> 1;
		}		
	}
}

static void textout(char *screen_mm,int xres,int yres,char *text,int xscale,int
yscale)
{
        int i=0;
        do{
		if ((xres+FONT_W*xscale))
		{
		
		}
	        showfont(screen_mm, 240, 160, xres, yres, (unsigned char *)fontdata_8x8+ (*text)*8, xscale, yscale);
	        text++;
	        i++;
                xres += FONT_W*xscale;
	  }while (*text!='\0');
}

int main(int argc, char **argv)
{
	int fd;
	int line_size, buff_size;
	char *screen_mm; 
	struct fb_var_screeninfo var_info;
	int xres = 0, yres = 0;
	
	fd = open("/dev/fb0", O_RDWR);
	if(fd == -1){
		printf("open /dev/fb0 failed\n");
		exit(1);
	}

	ioctl(fd, FBIOGET_VSCREENINFO, &var_info);	

	line_size = var_info.xres * var_info.bits_per_pixel / 8;
	buff_size = line_size * var_info.yres;
	printf("line_size = %d, buff_size = %d\n", line_size, buff_size);

	var_info.xoffset = 0;
	var_info.yoffset = 0;
	ioctl(fd, FBIOPAN_DISPLAY, &var_info);
	
	screen_mm = (char *)mmap(0, buff_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	bzero(screen_mm, buff_size);

	printf("showfont\n");

	textout(screen_mm, 40,100,"Fudan JHB",1,2);
	textout(screen_mm, 10,120,"www.fudantech.com",1,2);

/*	while(1){
		showfont(screen_mm, 120, 160, xres, 0, (unsigned char *)fontdata_8x8+560, 5, 5);		
		sleep(1);
		showfont(screen_mm, 120, 160, xres, 0, (unsigned char *)fontdata_8x8, 5, 5);
		xres = (xres + 2)%160;
	}
*/	close(fd);
	exit(0);	
}
