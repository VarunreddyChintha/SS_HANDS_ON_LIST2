/*==================================================================
 * Name : 9.c
 * Author : CHINTHA JOGGARI VARUN REDDY
 * Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal -  Use signal system call.
 * Date: 1ST OCTOBER,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

        int main() {
    printf("Ignoring SIGINT (Ctrl+C won't terminate now)...\n");
    signal(SIGINT, SIG_IGN);
    sleep(10);
    printf("\ndefault action for SIGINT (Ctrl+C will terminate now)...\n");
    signal(SIGINT, SIG_DFL);
    sleep(10);
    printf("\nProgram ended normally (if not killed by Ctrl+C)\n");
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 9.c
varun@varun:~/handson_2$ ./a.out
Ignoring SIGINT (Ctrl+C won't terminate now)...
^C^C^C^C^C
default action for SIGINT (Ctrl+C will terminate now)...
^C
============================================================================
*/
