/*==================================================================================
 * Name : 5.c
 * Author : CHINTHA JOGGARI VARUN REDDY
 * Description :5. Write a program to print the system limitation of
       a. maximum length of the arguments to the exec family of functions.
       b. maximum number of simultaneous process per user id.
       c. number of clock ticks (jiffy) per second.
       d. maximum number of open files
       e. size of a page
       f. total number of pages in the physical memory
       g. number of currently available pages in the physical memory.  #include<unistd.h>
  * Date: 1ST OCTOBER,2025
* ==================================================================================*/

#include<unistd.h>
#include<stdio.h>

int main(){

        printf("a. maximum length of arguments to exec family of functions %ld \n",sysconf(_SC_ARG_MAX));
	 printf("b.maximum number of simultaneous process per user id %ld \n",sysconf(_SC_CHILD_MAX));
	  printf("c. number of clock ticks (jiffy) per second %ld \n",sysconf(_SC_CLK_TCK));
	   printf("d. maximum number of open files %ld \n",sysconf(_SC_OPEN_MAX));
	    printf("e. size of a page %ld \n",sysconf(_SC_PAGESIZE));
	     printf("f. total number of pages in physical memory %ld \n",sysconf(_SC_PHYS_PAGES));
	      printf("g. number of currently available pages in the physical memory %ld \n",sysconf(_SC_AVPHYS_PAGES));
}
/*======================================================================================
 * Output:
 * varun@varun:~/handson_2$ cc 5.c
varun@varun:~/handson_2$ ./a.out
a. maximum length of arguments to exec family of functions 2097152
b.maximum number of simultaneous process per user id 60255
c. number of clock ticks (jiffy) per second 100
d. maximum number of open files 1024
e. size of a page 4096
f. total number of pages in physical memory 3901286
g. number of currently available pages in the physical memory 2190284 */
