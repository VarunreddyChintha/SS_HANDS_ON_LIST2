/*
============================================================================
Name : 10a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGSEGV using sigaction() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    int *ptr = NULL;
    *ptr = 50;

    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 10a.c
iiitb@nitheeshvemula:~/handson_2$ ./a.out
Caught SIGSEGV (Segmentation Fault)

============================================================================
*/
