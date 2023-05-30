#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main()
{
	int s_fd,len;
	char n;
	struct sockaddr_in add;
	s_fd=socket(AF_INET,SOCK_DGRAM,0);
	add.sin_family=AF_INET;
	add.sin_port=9003;
	add.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof (add);
	//result=connect(s_fd,(struct sockaddr *)&add,len);
	printf("Type your character:\n");
	scanf("%c",&n);
	sendto(s_fd,&n,1,0,(struct sockaddr*)&add,len);
	recvfrom(s_fd,&n,1,0,(struct sockaddr*)&add,&len);
	printf("Recieved :\n%c\n",n);
	return 0;
}
