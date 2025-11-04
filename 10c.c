/*
============================================================================
Name : 10c.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to catch SIGFPE using sigaction() system call
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
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    int x = 1 / 0;

    printf("%d\n", x);
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 10c.c
10c.c: In function ‘main’:
10c.c:26:15: warning: division by zero [-Wdiv-by-zero]
   26 |     int x = 1 / 0; // divide by zero
      |               ^
varun@varun:~/handson_2$ ./a.out
Caught SIGFPE (Floating Point Exception)



============================================================================
*/
