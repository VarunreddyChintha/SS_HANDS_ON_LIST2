/*
============================================================================
Name : 17a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :Program to run ls -l | wc using dup
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include<stdio.h>

#include<stdlib.h>
#include<unistd.h>

int main(){
int fd[2];
pipe(fd);

if(fork() ==0){
close(fd[0]);
close(1);

dup(fd[1]);

close(fd[1]);

execlp("ls","ls","-l",NULL);

perror("execlp failed");

return 1;

}
else{


close(fd[1]);

close(0);

dup(fd[0]);
close(fd[0]);
execlp("wc","wc",NULL);
perror("execlp failed");
return -1;

}

}
/*
============================================================================
Output:
varun@varun:~/handson_2$ nano 17a.c
varun@varun:~/handson_2$ cc 17a.c
varun@varun:~/handson_2$ ./a.out
      43      280     3873


============================================================================
*/
