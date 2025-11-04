/*
============================================================================
Name : 32c.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :C-program protect multiple pseudo resources(may be 2) using counting
semaphore
Date: 1ST October, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5
#define RESOURCES 2

sem_t sem;

void* use_resource(void* arg) {
    long id = (long)arg;

    sem_wait(&sem); // wait for resource
    printf("Thread %ld: using a resource\n", id);
    sleep(1);       // simulate work
    printf("Thread %ld: releasing resource\n", id);
    sem_post(&sem); // release resource

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    sem_init(&sem, 0, RESOURCES); // counting semaphore for 2 resources

    for(long i = 1; i <= NUM_THREADS; i++)
        pthread_create(&threads[i-1], NULL, use_resource, (void*)i);

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&sem);
    return 0;
}
/*
===============================================================================================
OUTPUT:

varun@varun:~/handson_2$ nano 32c.c
varun@varun:~/handson_2$ cc 32c.c
varun@varun:~/handson_2$ ./a.out
Thread 3: using a resource
Thread 1: using a resource
Thread 1: releasing resource
Thread 3: releasing resource
Thread 4: using a resource
Thread 2: using a resource
Thread 4: releasing resource
Thread 2: releasing resource
Thread 5: using a resource
Thread 5: releasing resource
===================================================================================
*/
