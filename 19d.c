/*
============================================================================
Name : 19d.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : Create a FIFO using mknod() system call
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    if (mknod("myfifo_19d", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(1);
    }
    printf("Done\n");
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 19d.c
varun@varun:~/handson_2$ ./a.out
Done
varun@varun:~/handson_2$ ls -li myfifo_19d
2644748 prw-rw-r-- 1 iiitb iiitb 0 Sep 30 14:31 myfifo_19d

============================================================================
*/
