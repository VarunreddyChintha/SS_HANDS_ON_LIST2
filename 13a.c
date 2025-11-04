/*
============================================================================
Name : 13a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to try catching SIGSTOP using sigaction() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    printf("Process ID: %d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;


    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
    }

    while (1) {
        printf("Running...\n");
        sleep(2);
    }

    return 0;
}
/*
============================================================================
OUTPUT:
============================================================================
varun@varun:~/handson_2$ ./a.out
Process ID: 9289
Running...
Running...
Running...
Running...

[1]+  Stopped                 ./a.out

============================================================================
*/
