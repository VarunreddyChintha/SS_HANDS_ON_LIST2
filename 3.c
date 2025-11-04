/*=================================================================================
 * Name: 3.c
 * Author : CHINTHA JOGGARI VARUN REDDY
 * Description :  Write a program to set (any one) system resource limit. Use setrlimit system call.
 * Date: 1ST OCTOBER,2025
 * =====================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>
#include<sys/resource.h>

int main(){
struct rlimit lim;
printf("R_LIMIT of system \n");
getrlimit(RLIMIT_NOFILE,&lim);
printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);

lim.rlim_cur=1096;
lim.rlim_max=105689;
setrlimit(RLIMIT_NOFILE,&lim);
printf("After setting limit \n");
getrlimit(RLIMIT_NOFILE,&lim);
printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);
}
/*=====================================================================
 * Output:
 * varun@varun:~/handson_2$ cc 3.c
varun@varun:~/handson_2$ ./a.out
R_LIMIT of system
Soft limit: 10240
Hard limit: 1048576
After setting limit
Soft limit: 1096
Hard limit: 105689
*/
