#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int s_fd,len;
	struct sockaddr_in add;
	char name[100], ser[100];
	s_fd=socket(AF_INET,SOCK_DGRAM,0);
	add.sin_family=AF_INET;
	add.sin_port=9003;
	add.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof (add);
	//result=connect(s_fd,(struct sockaddr *)&add,len);
	printf("Enter the message\n");
	gets(name);
	sendto(s_fd,name,sizeof(name),0,(struct sockaddr*)&add,len);
	recvfrom(s_fd,ser,sizeof(ser),0,(struct sockaddr*)&add,&len);
	printf("%Reading from server : %c\n");
	puts(ser);
	close(s_fd);
	return 0;
}
