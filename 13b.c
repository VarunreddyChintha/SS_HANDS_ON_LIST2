/*
============================================================================
Name : 13b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to send SIGSTOP signal using kill() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    if (kill(pid, SIGSTOP) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGSTOP to process %d\n", pid);

    return 0;
}
/*
============================================================================
OUTPUT:
============================================================================
varun@varun:~/handson_2$ ./a.out 9485
Sent SIGSTOP to process 9485


============================================================================
*/
