/*
============================================================================
Name        : 26.c
Author      : CHINTHA JOGGARI VARUN REDDY
Description : Program to send messages to  message queue
Date        : 1ST October, 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuff
{
	long msg_type;
	char msg[150];
};
int main()
{
    key_t key;
    key=ftok(".",'a');
    int msqid;
    msqid=msgget(key,0666);
    struct msgbuff message;
    message.msg_type=1;
    read(STDIN_FILENO,message.msg,sizeof(message.msg));
    if(msgsnd(msqid,&message,sizeof(message.msg),0)==-1)
    {
	    perror("msgsnd");
	    exit(EXIT_FAILURE);
    }
    return 0;
}
/*
============================================================================
OUTPUT :
varun@varun:~/hands_on2$ cc 26.c
varun@varun:~/hands_on2$ ./a.out
i am sending the message to the message queue
varun@varun:~/hands_on2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x6106012a 0          varun      666        150          1           


============================================================================
*/
