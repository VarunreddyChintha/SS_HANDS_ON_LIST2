/*
============================================================================
Name : 24.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :program to create a message queue and print the key and message
	queue id.
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main()
{
    key_t key;
    key=ftok(".",'a');
    int msqid;
    msqid=msgget(key,IPC_CREAT|0666);
    printf("the value of the key is %d\n",key);
    printf("the value of the message queue id is %d\n",msqid);
    return 0;
}
/*
============================================================================
OUTPUT:

varun@varun:~/hands_on2$ cc 24.c
varun@varun:~/hands_on2$ ./a.out
the value of the key is 1627783466
the value of the message queue id is 0
============================================================================
*/
