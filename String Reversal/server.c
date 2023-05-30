#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>


/*
//Logic - 1
void revstr(char *str)  
{ 
    int i, len, temp;  
    len = strlen(str);  
    for (i = 0; i < len/2; i++)  
    {  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }  
}
*/

/**/
//Logic - 2 
void revstr(char *str)  
{ 
    int i, len; 
    char ac[100];
    strcpy(ac,str); 
    len = strlen(str);  
    for (i = 0; i < len; i++)  
    	str[i]=ac[len-i-1];
}    
/**/


int main()
{
	int sfd,s_len,x;
	char a[100];
	struct sockaddr_in s_add;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	s_add.sin_family=AF_INET;
	s_add.sin_port=9003;
	s_add.sin_addr.s_addr=inet_addr("127.0.0.1");
	s_len=sizeof(s_add);
	
	
	bind(sfd,(struct sockaddr*)&s_add,s_len);
	while(1)
	{
		printf("Waiting on message recieve\n");
		x = sizeof(a);
		recvfrom(sfd,a,x,0,(struct sockaddr*)&s_add,&s_len);
		printf("Recieved:\n");
		puts(a);
		printf("sending\n");
		revstr(a);
		puts(a);
		sendto(sfd,a,x,0,(struct sockaddr*)&s_add,s_len);
	}
	return 0;
}
