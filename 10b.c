/*
============================================================================
Name : 10b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGINT using sigaction() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT (Ctrl+C pressed)\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("Running... Press Ctrl+C\n");
        sleep(1);
    }

    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handon_2$ cc 10b.c
varun@varun:~/handson_2$ ./a.out
Running... Press Ctrl+C
Running... Press Ctrl+C
^CCaught SIGINT (Ctrl+C pressed)
============================================================================
*/
