/*
============================================================================
Name : 30a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to create shared memory, write data, attach with O_RDONLY,
              detach, and remove shared memory.
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
int main()
{
	key_t key;
	key=ftok(".",'c');
	int shmid;
	shmid=shmget(key,512,IPC_CREAT|0766);
	char *data;
	data=(char *)shmat(shmid,(void*)0,0);
	printf("write the data to the shared memory segment\n");
	read(STDIN_FILENO,data,512);
	shmdt(data);
	return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/hands_on2$ cc 30a.c
varun@varun:~/hands_on2$ ./a.out
write the data to the shared memory segment
i am writing the data to the shared memory

============================================================================
*/

