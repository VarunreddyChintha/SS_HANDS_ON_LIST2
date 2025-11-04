/*
============================================================================
Name : 8g.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGPROF using setitimer() system call
Date: 1st OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGPROF (profiling timer expired)\n");
}

int main() {
    signal(SIGPROF, handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_PROF, &timer, NULL);
    while (1); 
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 8g.c
varun@varun:~/handson_2$ ./a.out
Caught SIGPROF (profiling timer expired)
Caught SIGPROF (profiling timer expired)
Caught SIGPROF (profiling timer expired)


============================================================================
*/
