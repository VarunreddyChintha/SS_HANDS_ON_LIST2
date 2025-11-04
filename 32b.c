/*
============================================================================
Name : 32b.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :C-program to protect shared mem from concurrent write access
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

int shared_data = 0;
sem_t sem;

void* write_shared(void* arg) {
    sem_wait(&sem);
    int temp = shared_data;
    temp++;
    printf("Thread %ld: writing %d\n", (long)arg, temp);
    shared_data = temp;
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    sem_init(&sem, 0, 1);

    for(long i = 1; i <= NUM_THREADS; i++)
        pthread_create(&threads[i-1], NULL, write_shared, (void*)i);

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("Final shared data = %d\n", shared_data);

    sem_destroy(&sem);
    return 0;
}
/*
==========================================================================================

OUTPUT:

varun@varun:~/handson_2$ cc 32b.c
varun@varun:~/handson_2$ ./a.out
Thread 3: writing 1
Thread 1: writing 2
Thread 2: writing 3
Thread 4: writing 4
Thread 5: writing 5
Final shared data = 5
varun@varun:~/handson_2$ ./a.out
Thread 2: writing 1
Thread 1: writing 2
Thread 3: writing 3
Thread 4: writing 4
Thread 5: writing 5
Final shared data = 5
===========================================================================================
*/
