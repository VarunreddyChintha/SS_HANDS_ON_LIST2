
/*
 ==========================================================================================================
Program: 4.c
Author : CHINTHA JOGGARI VARUN REDDY
Descritpion :Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date : 1ST OCTOBER,2025
===========================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long int rdtsc(){
	unsigned long long curr_time;
	__asm__ __volatile__("rdtsc":"=A"(curr_time));
	return curr_time;
}
int main(){
        long long int start,end;
        printf("I am calling getppid() 100 times \n");
	start = rdtsc();
         for (int i = 0; i < 100; i++) {
        getppid();
    }
	end=rdtsc();
	printf("time taken is %llu nanoseconds \n",end-start);

}

/* =================================================================================
 * Output:
 *varun@varun:~/handson_2$ cc 4.c
 varun@varun:~/handson_2$ ./a.out
I am calling getppid() 100 times
time taken is 119000 nanoseconds
  */
