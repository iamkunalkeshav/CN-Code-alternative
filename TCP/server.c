#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	int serv_sockfd,serv_len,cli_sockfd, cli_len;
	char a[100], b[100] = {'A'};
	struct sockaddr_in serv_address, cli_address;
	serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_address.sin_family=AF_INET;
	serv_address.sin_port=9003;
	serv_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_len=sizeof(serv_address);
	bind(serv_sockfd,(struct sockadfr*)&serv_address,serv_len);
	listen(serv_sockfd,5);
	while(1)
	{
		printf("SERVER IS WAITING...\n");
		cli_len = sizeof(cli_address);
		cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&serv_address,&serv_len);
		printf("Reading message from client...");
		read(cli_sockfd,a,sizeof(a));
		puts(a);
		gets(b);
		write(cli_sockfd, b, sizeof(b));
		close(cli_sockfd);
	}
	return 0;
}
