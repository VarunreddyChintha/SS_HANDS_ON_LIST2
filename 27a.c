/*
============================================================================
Name : 27a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to receive messages from a message queue with flag 0
Date: 1ST OCTOBER, 2025.
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
    ssize_t bytes;
    bytes=msgrcv(msqid,&message,sizeof(message.msg),0,0);
    if(bytes>1)
    {
	    printf("the message in the message queue is : %s\n",message.msg);
    }


    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/hands_on2$ cc 27a.c
varun@varun:~/hands_on2$ ./a.out
the message in the message queue is : i am sending the message to the message queue




============================================================================
*/

