/*
============================================================================
Name : 8b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGINT using signal() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT");
    exit(0);
}

int main() {
    signal(SIGINT, handler);
    while (1) {
        printf(" Press Ctrl+C\n");
        sleep(1);
    }
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 8a.c
varun@varun:~/handson_2$ ./a.out
Press Ctrl+C
Press Ctrl+C
^CCaught SIGINT

============================================================================

*/
