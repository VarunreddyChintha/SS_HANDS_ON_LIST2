/*
============================================================================
Name : 32d.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :C-program to remove created semaphores
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t sem1, sem2, sem3;

    // Initialize semaphores
    sem_init(&sem1, 0, 1); // binary semaphore
    sem_init(&sem2, 0, 2); // counting semaphore
    sem_init(&sem3, 0, 3); // counting semaphore

    printf("3 semaphores created.\n");



    // Destroy semaphores
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);

    printf("3 semaphores removed.\n");
    return 0;
}



/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ nano 32d.c
varun@varun:~/hanfdson_2$ cc 32d.c
varun@varun:~/handson_2$ ./a.out
3 semaphores created.
3 semaphores removed.

============================================================================
*/
