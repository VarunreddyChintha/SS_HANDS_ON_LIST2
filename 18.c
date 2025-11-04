/*
============================================================================
Name : 18.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc. Using dup2.
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
int pipe1[2],pipe2[2];

pipe(pipe1);
pipe(pipe2);

if(fork()==0){


close(pipe1[0]);

dup2(pipe1[1],1);

execlp("ls","ls","-l",NULL);

perror("execlp ls");
return 1;
}

if(fork()==0){



close(pipe1[1]);

close(pipe2[0]);

dup2(pipe1[0],0);


dup2(pipe2[1],1);



execlp("grep","grep","^d",NULL);

perror("execlp grep");
return 1;
}
else{

close(pipe1[0]);

close(pipe1[1]);

close(pipe2[1]);
dup2(pipe2[0],0);


execlp("wc","wc","-l",NULL);
perror("execlp wc");
return 1;
}
return 0;
}
/*
============================================================================
OUTPUT:

varun@varun:~/handson_2$ mkdir 1
varun@varun:~/handson_2$ mkdir 2
varun@varun:~/handson_2$ ls
1  14.c  15.c  16.c  17a.c  17b.c  17c.c  18.c  2  6.c  7.c  a.out  socket.c
varun@varun:~/handson_2$ cc 18.c
varun@varun:~/handson_2$ ./a.out
2
============================================================================
*/
