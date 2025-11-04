/*
============================================================================
Name : 11.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : C program to ignore a SIGINT signal and then reset it to default
              action using sigaction() system call.
Date: 29 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;


    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("Ignoring SIGINT (Ctrl+C won't terminate now)...\n");
    sleep(10);


    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("\n default action for SIGINT (Ctrl+C will terminate now)...\n");
    sleep(10);

    printf("\nProgram ended normally (if not killed by Ctrl+C)\n");
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 11.c
iiitb@nitheeshvemula:~/handson_2$ ./a.out
Ignoring SIGINT (Ctrl+C won't terminate now)...
^C^C
 default action for SIGINT (Ctrl+C will terminate now)...
^C
varun@varun:~/handson_2$

============================================================================
*/
