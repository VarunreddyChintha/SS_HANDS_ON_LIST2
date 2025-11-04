/*
============================================================================
Name : 29.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to remove a System V message queue using msgctl()
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
    msqid=msgget(key,0666);
    msgctl(msqid,IPC_RMID,NULL);
    printf("the message queue is removed\n");
    return 0;
}
/*
============================================================================
OUTPUT:
the message queue is removed
============================================================================
*/
