/*
============================================================================
Name : 28.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to change the permission of an existing message queue
              using msqid_ds structure
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
int main()
{
    key_t key;
    key=ftok(".",'a');
    int msqid;
    msqid=msgget(key,0666);
    struct msqid_ds acc;
    msgctl(msqid,IPC_STAT,&acc);
    acc.msg_perm.mode=0644;
    if(msgctl(msqid,IPC_SET,&acc)==-1)
    {
	    perror("msgctl-IPC_SET\n");
	    exit(EXIT_FAILURE);
    }
    printf("new permissions are: %o\n",acc.msg_perm.mode);
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/hands_on2$ cc 28.c
varun@varun:~/hands_on2$ ./a.out
new permissions are: 644
============================================================================
*/
