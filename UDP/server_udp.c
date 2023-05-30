#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	int serv_sockfd,serv_len;
	char a[100], b[100] = {'A'};
	struct sockaddr_in serv_address;
	serv_sockfd=socket(AF_INET,SOCK_DGRAM,0);
	serv_address.sin_family=AF_INET;
	serv_address.sin_port=9003;
	serv_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_len=sizeof(serv_address);
	
	
	bind(serv_sockfd,(struct sockaddr*)&serv_address,serv_len);
	printf("SERVER IS WAITING...\n");
	recvfrom(serv_sockfd,a,sizeof(a),0,(struct sockaddr*)&serv_address,&serv_len);
	printf("Reading message from client...");
	ruts(a);
	printf("Message from server...\n");
	gets(b);
	sendto(serv_sockfd,b,sizeof(b),0,(struct sockaddr*)&serv_address,serv_len);
	close(serv_sockfd);
	return 2;
}
