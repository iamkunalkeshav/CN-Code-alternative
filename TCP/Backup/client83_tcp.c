#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
 
 int sockfd,len,result;
  struct sockaddr_in address;
 char ser[100],name[100];
 
 sockfd = socket(AF_INET,SOCK_STREAM,0);
 address.sin_family = AF_INET;
 address.sin_port = 9004;
 address.sin_addr.s_addr = inet_addr("127.0.0.1");
 
 len = sizeof(address);
 
 result = connect(sockfd,(struct sockaddr*) &address,len);
 
 if(result==-1)
 {
 printf("unable to connect \n");
 exit(1);
 }
 
 printf("enter the message ");
 gets(name);
 write(sockfd,name,sizeof(name));
 read(sockfd,ser,sizeof(ser));
 
 printf("\n reading from server : %c \n");
 puts(ser);
 close(sockfd);
 return 0 ;
 }
 
    
