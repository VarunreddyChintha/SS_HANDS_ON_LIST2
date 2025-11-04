/*
============================================================================
Name : 8f.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGVTALRM using setitimer() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGVTALRM (virtual timer expired)\n");
}

int main() {
    signal(SIGVTALRM, handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while (1);
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 8f.c
varun@varun:~/handson_2$ ./a.out
Caught SIGVTALRM (virtual timer expired)
Caught SIGVTALRM (virtual timer expired)
Caught SIGVTALRM (virtual timer expired)
Caught SIGVTALRM (virtual timer expired)


============================================================================
*/
