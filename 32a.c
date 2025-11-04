/*
============================================================================
Name : 32a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :C-program to rewrite the ticket num creation using semaphore

Date: 1st OctoberS, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5

int ticket = 0;       // shared ticket number
sem_t sem;            // semaphore

void* create_ticket(void* arg) {
    sem_wait(&sem);   // enter critical section
    ticket++;
    printf("Thread %ld: Ticket number = %d\n", (long)arg, ticket);
    sem_post(&sem);   // leave critical section
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    sem_init(&sem, 0, 1); // binary semaphore

    for(long i = 1; i <= NUM_THREADS; i++)
        pthread_create(&threads[i-1], NULL, create_ticket, (void*)i);

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&sem); // remove semaphore
    return 0;
}
/*
==========================================================================================

OUTPUT:

varun@varun:~/handson_2$ nano 32a.c
varun@varun:~/handson_2$ cc 32a.c
varun@varun:~/handson_2$ ./a.out
Thread 1: Ticket number = 1
Thread 3: Ticket number = 2
Thread 5: Ticket number = 3
Thread 4: Ticket number = 4
Thread 2: Ticket number = 5
varun@varun:~/handson_2$ ./a.out
Thread 1: Ticket number = 1
Thread 3: Ticket number = 2
Thread 5: Ticket number = 3
Thread 4: Ticket number = 4
Thread 2: Ticket number = 5
varun@varun:~/handson_2$ ./a.out
Thread 3: Ticket number = 1
Thread 1: Ticket number = 2
Thread 2: Ticket number = 3
Thread 4: Ticket number = 4
Thread 5: Ticket number = 5
======================================================================================
*/
