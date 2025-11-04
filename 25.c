/*
============================================================================
Name        : 25.c
Author      : CHINTHA JOGGARI VARUN REDDY
Description : Program to print a message queue's details using msqid_ds and
ipc_perm
Date        : 1ST OCTOBER, 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<time.h>
int main()
{
	key_t k=ftok(".",'a');
	if(k==-1)
	{
		perror("error generating key");
		exit(EXIT_FAILURE);
	}
	int msqid;
	msqid=msgget(k,0666);
	struct msqid_ds acc;
	msgctl(msqid,IPC_STAT,&acc);
	printf("Access permissions are : %o\n",acc.msg_perm.mode);
	printf("owner uid is : %d\n",acc.msg_perm.uid);
	printf("owner gid is : %d\n",acc.msg_perm.gid);
	printf("creator uid : %d\n",acc.msg_perm.cuid);
	printf("creator gid is :%d\n",acc.msg_perm.cgid);
	 printf("Last msgsnd time: %s", ctime(&acc.msg_stime));
    printf("Last msgrcv time: %s", ctime(&acc.msg_rtime));
    printf("Last change time: %s", ctime(&acc.msg_ctime));
    printf("Current number of bytes in queue: %lu\n",acc.__msg_cbytes);
    printf("Number of messages in queue: %lu\n",acc.msg_qnum);
    printf("Max bytes allowed in queue: %lu\n",acc.msg_qbytes);
    printf("PID of last msgsnd: %d\n", acc.msg_lspid);
    printf("PID of last msgrcv: %d\n", acc.msg_lrpid);

return 0;
}
/*
============================================================================
OUTPUT :
varun@varun:~/hands_on2$ cc 25.c
varun@varun:~/hands_on2$ ./a.out
Access permissions are : 666
owner uid is : 1000
owner gid is : 1000
creator uid : 1000
creator gid is :1000
Last msgsnd time: Thu Jan  1 05:30:00 1970
Last msgrcv time: Thu Jan  1 05:30:00 1970
Last change time: Wed Oct  1 18:19:50 2025
Current number of bytes in queue: 0
Number of messages in queue: 0
Max bytes allowed in queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0


============================================================================
*/
