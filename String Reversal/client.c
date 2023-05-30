#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>


int main()
{
	int s_fd,len,x;
	char name[100];
	struct sockaddr_in add;
	s_fd=socket(AF_INET,SOCK_DGRAM,0);
	add.sin_family=AF_INET;
	add.sin_port=9003;
	add.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(add);
	while(1)
	{
		printf("Type your message:\n");
		gets(name);
		x = sizeof(name);
		sendto(s_fd,name,x,0,(struct sockaddr*)&add,len);
		recvfrom(s_fd,name,x,0,(struct sockaddr*)&add,&len);
		printf("Recieved:\n");
		puts(name);
	}
	return 0;
}
