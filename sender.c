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
	struct message msg;
	key =131;
	msgid = msgget(key, IPC_CREAT|0666);
	printf("\n q=%d\n",msgid);
	strcpy(msg.mtext,"Hello World!\n");
	msg.mtype =1;
	len = strlen(msg.mtext);
	if(msgsnd(msgid, &msg, len, 0)==-1)
	{
		printf("\n!ERROR!\n");
		exit(1);
	}
	return 0;
}
