/*
============================================================================
Name : 27b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to receive messages from a message queue with IPC_NOWAIT
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
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
    ssize_t bytes;
    bytes=msgrcv(msqid,&message,sizeof(message.msg),0,IPC_NOWAIT);
    if(bytes==-1)
    {
	    if(errno==ENOMSG)
		    printf("no message is availabe\n");
	    else
		    printf("msgrcv");

    }
    else
	    printf("recieved message is :%s\n",message.msg); 
    return 0;
}
/*
============================================================================
OUTPUT:
/*
varun@varun:~/hands_on2$ cc 27b.c
varun@varun:~/hands_on2$ ./a.out
no message is availabe

============================================================================
*/
