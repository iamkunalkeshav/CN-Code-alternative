#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int sockfd,len,result;
	struct sockaddr_in address;
	char name[100], ser[100];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_port=9011;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof (address);
	result=connect(sockfd,(struct sockaddr *)&address,len);
	if(result == -1)
	{
		perror("Unable to connect!\n");
		exit(1);
	}
	while(1)
	{
		printf("enter the message ");
 		gets(name);
 		write(sockfd,name,sizeof(name));
 		read(sockfd,ser,sizeof(ser));
 
 		printf("\n reading from server : %c \n");
		puts(ser);
	}
	return 0;
}

