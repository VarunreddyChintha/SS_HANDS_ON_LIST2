/*
============================================================================
Name : 23.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :Program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    // Maximum open files
    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum open files: %ld\n", max_files);

    // Pipe atomic write size (gives an idea of pipe buffer)
    long pipe_buf = sysconf(_PC_PIPE_BUF);
    if (pipe_buf == -1)
        printf("Could not get pipe buffer size\n");
    else
        printf("Pipe buffer size (atomic write size): %ld bytes\n", pipe_buf);

    return 0;
}

/*
============================================================================
Output:
varun@varun:~/handson_2$ cc 23.c
varun@varun:~/handson_2$ ./a.out
Maximum open files: 1024
Pipe buffer size (atomic write size): 16 bytes
============================================================================
*/
