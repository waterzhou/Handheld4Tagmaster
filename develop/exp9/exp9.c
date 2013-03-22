#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	
	if( (fp = fopen("/mnt/usbtest","w+")) == NULL)
	{
		printf("%p\n",fp);
		printf("Can not open file!\n");
		exit(1);
	}
	fprintf(fp,"%s","Hello World !\n");
	fprintf(fp,"%s","Fudan JHB ARM Linux Platform!\n");

	fclose(fp);
}
