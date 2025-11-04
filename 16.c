/*
============================================================================
Name : 16.c
Author : CHINTHA JOGGARI VARUN  REDDY
Description :program to send and receive data from parent to child vice versa.
Two way communication using two pipes
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main(){

int fd[2];
int fd2[2];
pipe(fd2);

pipe(fd);




if(!fork()){
char msg[] = "Hi from child";
write(fd[1],msg,strlen(msg));

sleep(1);

char buf[80];
int n =read(fd2[0],buf,sizeof(buf));
buf[n] = '\0';
printf("Read in Child process wrote by Parent;%s\n",buf);

}
else{

sleep(1);
char msg[] = "Hi from Parent";
write(fd2[1],msg,strlen(msg));
sleep(1);
char buf[80];
int n =read(fd[0],buf,sizeof(buf));
buf[n] = '\0';
printf("Read by Parent,Wrote by Child Process:%s\n",buf);

}
return 0;
}
/*
============================================================================
Output:

varun@varun:~/handson_2$ cc 16.c
varun@varun:~/handson_2$ ./a.out
Read in Child process wrote by Parent;Hi from Parent
Read by Parent,Wrote by Child Process:Hi from child

============================================================================
*/
