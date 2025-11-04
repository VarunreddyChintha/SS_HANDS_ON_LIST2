/*
============================================================================
Name : 31a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : Create a binary semaphore and initialize it to 1
Date: 1ST October, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
int main()
{
	key_t key;
	key=ftok(".",'b');
	union semun arg;
        int semid;
	semid=semget(key,1,IPC_CREAT|0644);
	arg.val=1;
	semctl(semid,0,SETVAL,arg);
	printf("binary semaphore created and initialized to 1\n");
	return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/hands_on2$ cc 31a.c
varun@varun:~/hands_on2$ ./a.out
binary semaphore created and initialized to 1

============================================================================
*/
