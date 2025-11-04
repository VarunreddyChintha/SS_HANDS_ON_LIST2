/*
============================================================================
Name : 8d.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGALRM using alarm() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM (from alarm())\n");
}

int main() {
    signal(SIGALRM, handler);
    alarm(3);
    pause();
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 8d.c
varun@varun:~/handson_2$ ./a.out
Caught SIGALRM (from alarm())

============================================================================
*/
