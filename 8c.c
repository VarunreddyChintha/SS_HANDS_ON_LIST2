/*
============================================================================
Name : 8c.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGFPE using signal() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handler);
    int x = 1 / 0; 
    printf("%d\n", x);
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 8c.c
varun@varun:~/handson_2$ ./a.out
Caught SIGFPE (Floating Point Exception)
============================================================================
*/
