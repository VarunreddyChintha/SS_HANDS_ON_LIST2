/*
============================================================================
Name : 17b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :program to execute ls -l | wc using dup2
Date: 19 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

#include<stdlib.h>


int main(){

int fd[2];

pipe(fd);

if(fork()==0){

close(fd[0]);
dup2(fd[1],1);
execlp("ls","ls","-l",NULL);
perror("execlp ls");
return 0;

}
else{
close(fd[1]);
dup2(fd[0],0);
execlp("wc","wc",NULL);
perror("execlp wc");
return 1;

}

return 0;
}
/*
============================================================================
OUTPUT :

varun@varun:~/handson_2$ nano 17b.c
varun@varun:~/handson_2$ cc 17b.c
varun @varun:~/handson_2$ ./a.out
     44      389     2123

============================================================================
*/
