#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>


int main()
{
	int s_fd,len;
	char a;
	struct sockaddr_in add;
	s_fd=socket(AF_INET,SOCK_DGRAM,0);
	add.sin_family=AF_INET;
	add.sin_port=9003;
	add.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(add);
	
	bind(s_fd,(struct sockaddr*)&add,len);
	while(1)
	{
		printf("SERVER ON\n");
		recvfrom(s_fd,&a,1,0,(struct sockaddr*)&add,&len);
		a++;
		sendto(s_fd,&a,1,0,(struct sockaddr*)&add,len);
	}
	return 0;
}
