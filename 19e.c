/*
============================================================================
Name : 19e.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : Create a FIFO using mkfifo() library function
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    if (mkfifo("myfifo_19e", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    printf("Created\n");
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 19e.c
varun@varun:~/hands_on2$ ./a.out
Created
varun@varun:~/handson_2$ ls -li myfifo_19e
2644535 prw-rw-r-- 1 iiitb iiitb 0 Sep 30 14:29 myfifo_19e

============================================================================
*/
