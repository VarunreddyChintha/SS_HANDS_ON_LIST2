/*
============================================================================
Name : 17c.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :program to execute ls -l | wc using fcntl
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

#include<stdlib.h>
#include<fcntl.h>



int main(){

int fd[2];

pipe(fd);

if(fork()==0){

close(fd[0]);
close(1);
fcntl(fd[1],F_DUPFD,1);
execlp("ls","ls","-l",NULL);
perror("execlp ls");
return 0;

}
else{
close(fd[1]);
close(0);
fcntl(fd[0],F_DUPFD,0);
execlp("wc","wc",NULL);
perror("execlp wc");
return 1;

}

return 0;
}
/*
============================================================================
OUTPUT:

varun@varun:~/handson_2$ nano 17c.c
varun@varun:~/handson_2$ cc 17c.c
varun@varun:~/handsn_2$ ./a.out
     45      398     2173

============================================================================
*/
