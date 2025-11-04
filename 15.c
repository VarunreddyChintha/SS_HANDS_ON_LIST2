/*
============================================================================
Name : 15.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :C program using pipe() to send data from parent to child
Date: 1ST OCTOBERs, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
 int fd[2];
 char read_buff[1024];
 char write_buff[1024];
 pipe(fd);
 if(!fork())
  {
          close(fd[0]);
     write(fd[1],"Hi how are you \n",sizeof(write_buff));
  }
 else
 {
         close(fd[1]);
    read(fd[0],read_buff,sizeof(read_buff));
    printf("the message recieved from parent is : %s\n",read_buff);
    wait(0);
  }
  return 0;
}
/*
============================================================================
Output:
varun@varun:~/hands_on2$ cc 15.c
varun@varun:~/hands_on2$ ./a.out
the message recieved from parent is : Hi how are you 


============================================================================
*/













































































































