#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>


int main()
{
	int counter=0;
	int serv_sockfd,serv_len,cli_sockfd,processId,cli_len;
	struct sockaddr_in serv_address,cli_address;
	char a[100], b[100];
	serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_address.sin_family=AF_INET;
	serv_address.sin_port=9011;
	serv_address.sin_addr.s_addr = INADDR_ANY;
	serv_len=sizeof(serv_address);
	bind(serv_sockfd,(struct sockaddr*)&serv_address,serv_len);
	listen(serv_sockfd,5);
	printf("SERVER IS WORKING..\n");

	while(1)
	{
		counter++;
		cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&serv_address,&serv_len);	
		processId = fork();
		if(processId==0)
		{
			
			printf("\nClient %d : Connected\n",counter);
			close(serv_sockfd);
			while(1)
			{
				printf("server is waiting .. ");
				  cli_len = sizeof(cli_address);
				  
				  cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&cli_address,&cli_len);
				  
				  read(cli_sockfd,a,sizeof(a));
				  printf("reading message from client : ");
				  puts(a);

				  write(cli_sockfd, b ,sizeof(b));
				  gets(b);
				  close(cli_sockfd);
			}
			printf("\nClient %d : Connection terminated\n", counter);
			exit(0);
		}
		close(cli_sockfd);
	}
	return 0;
}
