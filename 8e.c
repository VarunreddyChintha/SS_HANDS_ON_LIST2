/*
============================================================================
Name :8e.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGALRM using setitimer() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM (from setitimer())\n");
}

int main() {
    signal(SIGALRM, handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    pause();
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 8e.c
varun@varun:~/handson_2$ ./a.out
Caught SIGALRM (from setitimer())

============================================================================
*/
