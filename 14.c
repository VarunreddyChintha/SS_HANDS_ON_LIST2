/*
============================================================================
Name : 14.c
Author :CHNTHA JOGGARI VARUN REDDY
Description :C-program to create a pipe,write to pipe ,read from pipe,and
		print on monitor
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main()
{
   int fd[2];
   pipe(fd);
   ssize_t bytes_write;
   char buffer[]=" writing to the pipe";
   bytes_write=write(fd[1],buffer,sizeof(buffer));
   char display[1024];
   read(fd[0],display,bytes_write);
   printf("read from the pipe:%s\n",display);
 return 0;
}
/*
============================================================================
Output:
varun@varun:~/hands_on2$ cc 14.c
varun@varun:~/hands_on2$ ./a.out
read from the pipe: writing to the pipe


============================================================================
*/
