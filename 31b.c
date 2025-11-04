/*
============================================================================
Name : 31b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : Create a counting semaphore set and initialize values
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<sys/ipc.h>
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};

int main()
{
	key_t key;
	key=ftok(".",'v');
	int semid;
	union semun arg;
	arg.val=3;
	semid=semget(key,1,IPC_CREAT|0644);
        semctl(semid,0,SETVAL,arg);
	printf("coounting semaphore created and set the value to:3\n");
	return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/hands_on2$ cc 31b.c
varun@varun:~/hands_on2$ ./a.out
coounting semaphore created and set the value to:3

============================================================================
*/
