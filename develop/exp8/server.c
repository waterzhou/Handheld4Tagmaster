#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>

#define MY_PORT         9000

int main(int argc ,char **argv) 
{ 
 int listen_fd,accept_fd; 
 struct sockaddr_in     client_addr; 
 int n; 
 FILE *fp;
  
 struct sigaction sa;
 memset(&sa,'\0',sizeof(sigaction)); 
 sa.sa_handler=SIG_IGN;
 sa.sa_flags=SA_NOCLDSTOP;

 sigaction(SIGCHLD,&sa,NULL );

 if((listen_fd=socket(AF_INET,SOCK_STREAM,0))<0) 
  { 
        printf("Socket Error:%s\n\a",strerror(errno)); 
        exit(1); 
  } 
  
 bzero(&client_addr,sizeof(struct sockaddr_in)); 
 client_addr.sin_family=AF_INET; 
 client_addr.sin_port=htons(MY_PORT); 
 client_addr.sin_addr.s_addr=htonl(INADDR_ANY); 
 n=1; 
 setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int)); 
 if(bind(listen_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))<0) 
  { 
        printf("Bind Error:%s\n\a",strerror(errno)); 
        exit(1); 
  } 
  listen(listen_fd,5); 
  printf("Listening to the connect request of client......\n");
  while(1) 
  { 
   accept_fd=accept(listen_fd,NULL,NULL); 
   if((accept_fd<0)&&(errno==EINTR)) 
          continue; 
   else if(accept_fd<0) 
    { 
        printf("Accept Error:%s\n\a",strerror(errno)); 
        continue; 
    } 
    
  if((n=fork())==0) 
   { 
   	char  *tmp = NULL;
        char buffer[200*1024]   = {0}; 

        close(listen_fd); 
        n=read(accept_fd,buffer,1024); 
        printf("Begining to recieve the file......\n");
	
	tmp = strchr (buffer,'\0');//寻找buffer中第一个出现的'\0'字符
	
	if (tmp != NULL) // 若有一个以'\0'结尾的字符串,则这个字符串为文件名
	{
	  fp = fopen (buffer, "w+"); // 以可读可写方式打开文件，若没有则创建这个文件
	  if (fp == NULL)
	  {
	    printf("Create File Error!\n");
	    exit (1);
	  }
	  
	  if (strlen(buffer) < (n - 1))// 除了文件名还有别的内容 
	  {
	    tmp++;//指针指向'\0'之后的内容
	    fwrite (tmp, sizeof(char), n - strlen(buffer) - 1, fp);// 向文件中写文件内容
	  }
	  
	  while ((n = read(accept_fd, buffer, 1024)) >= 0) // 继续读取网络传递过来的内容
	  {
	    if (n > 0) // 有内容
	    { 
	      fwrite (buffer, sizeof(char), n, fp);//写到文件中
	    }
	    else 
	    {
	       fclose (fp);//文件传送结束,关闭文件.
	       break;
	    }
	  }
	  
	  if (n < 0) // 出错
	  {
	    fclose (fp);
	    printf("Read data from network error!\n");
	    exit (1);
	  }	  
	  printf("File transfer successfully!......\n");
	} 
	
        close(accept_fd); 
        exit(0); 
   } 
   else if(n<0) 
        printf("Fork Error:%s\n\a",strerror(errno)); 
   close(accept_fd); 
   
} 
  printf("\nReceive finished,press any key to return\n");
   getch();
}  
