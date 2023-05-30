#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>

struct message
{
	long mtype;
	char mtext[15];
};

int main()
{
	int msgid, len=20;
	key_t key;
	struct message buff;
	key =131;
	msgid = msgget(key, IPC_CREAT|0666);
	printf("\n q=%d",msgid);
	if(msgrcv(msgid, &buff, len, 0,0)==-1)
	{
		printf("!Message receive failed!\n");
		exit(1);
	}
	printf("\n Message Received- %s\n",buff.mtext);
	return 0;
}
