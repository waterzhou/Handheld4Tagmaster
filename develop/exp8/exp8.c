#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>


#define PORTNUM         9000          // Port number
#define HOSTNAME        "192.168.1.16" //"200.255.255.3" //192.168.0.90" 

int main(int argc,char *argv[])
{ 
  FILE *fp;
  char *ch = NULL;
  int size, ServerSock ;              // Socket bound to the server
  char fileName[256];
  char buffer[900*1024];               //发送缓冲区
  struct sockaddr_in destination_sin;        // Server socket address
  struct hostent *phostent;           // Points to the HOSTENT structure
                                      // of the server
    
  if (argc < 2)
  {
	fprintf (stderr, "Usage: client FileName !\n");
	exit (1);
  }

    
  // Create a TCP/IP socket that is bound to the server.
  if ((ServerSock = socket (AF_INET, SOCK_STREAM, 0)) < 0)
  {
    fprintf (stderr, "Allocating socket failed");
    exit(1);
  }

  // Fill out the server socket's address information.
  destination_sin.sin_family = AF_INET;

  // Assign the socket IP address.
  destination_sin.sin_addr.s_addr=inet_addr(HOSTNAME);

  // Convert to network ordering.
  destination_sin.sin_port = htons (PORTNUM);      

  // Establish a connection to the server socket.
  if (connect (ServerSock, 
               (struct sockaddr *) &destination_sin, 
               sizeof (destination_sin)) <0) 
  {
    fprintf (stderr,"Connecting to the server failed");
    close(ServerSock);
    exit(1);
  }
  
  ch = strrchr (argv[1], '/'); // ch指向最后一个'\'号

  if ((ch != NULL) && (strlen(ch) > 0))//如果传入的参数带路径名,且最后一个字符不是'\'
  {
	ch++;
	strcpy (fileName, ch); //路径名去掉后的文件名拷入 fileName中
  }
  else //如果传入的参数不带路径名,则直接把参数拷贝到fileName中
  {
	strcpy (fileName, argv[1]); // 取得要传送的文件名
  }

  //打开要传送的文件
   if( (fp  = fopen(argv[1], "r" )) == NULL )

  {
	fprintf( stderr, "The file was not opened\n" );
	exit (1);
  }

   printf ("Uploading file %s to %s ...", fileName, HOSTNAME);

   // 传送文件名
  if (send (ServerSock, fileName, strlen(fileName) + 1, 0) <0)
  {
	  fprintf(stderr, "Sending file name error \n");
	  exit (1);
  }
  
  //传送文件内容
  while((size = fread(buffer,sizeof(char),sizeof(buffer), fp))>0)
  {
    printf(".");
  	if (send (ServerSock, buffer, size, 0) < 0)
  	{
  	  fprintf (stderr,"Sending data to the server failed");
  	}
  }
  
  // Disable sending on ServerSock.
  close(ServerSock);
  
  printf ("\nUploading finished\n");

  exit(0);
}
