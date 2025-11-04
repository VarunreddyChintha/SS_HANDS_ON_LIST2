/*
============================================================================
Name : 12.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to create an orphan process. The child process sends
              SIGKILL to the parent process using kill() system call.
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child: My PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(2);
        printf("Child: Sending SIGKILL to parent (PID = %d)\n", getppid());
        kill(getppid(), SIGKILL);
        sleep(3);
        printf("Child: Now my Parent PID = %d\n", getppid());
        while (1) {
            sleep(1);
        }
    } else {
        printf("Parent: My PID = %d, Child PID = %d\n", getpid(), pid);
        while (1) {
            sleep(1);
        }
    }

    return 0;
}
/*
============================================================================
OUTPUT:
============================================================================
varun@varun:~/hands_on2$ cc 12.c
varun@varun:~/hands_on2$ ./a.out
Parent: My PID = 8629, Child PID = 8630
Child: My PID = 8630, Parent PID = 8629
Child: Sending SIGKILL to parent (PID = 8629)
Killed
varun@varun:~/hands_on2$ Child: Now my Parent PID = 2443

============================================================================
*/
