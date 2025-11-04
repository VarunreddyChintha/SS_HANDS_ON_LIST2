/*
============================================================================
Name : 30b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to create shared memory, write data, attach with O_RDONLY,
              detach, and remove shared memory.
Date: 1ST October, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
int main()
{
	key_t key;
	key=ftok(".",'c');
	int shmid;
	shmid=shmget(key,512,0766);
	char *data;
	data=(char *)shmat(shmid,(void*)0,0);
	printf(" the data in the0 shared memory segment is : %s\n",data);
	shmdt(data);
        printf("i am removing the shared memory segment\n");
        shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/hands_on2$ cc 30b.c
varun@varun:~/hands_on2$ ./a.out
 the data in the0 shared memory segment is : i am writing the data to the shared memory

i am removing the shared memory segment

============================================================================
*/

