/*===================================================================================
 * Name: 6.c
 * Author : CHINTHA JOGGARI VARUN REDDY
 * Description: 6. Write a simple program to create three threads.
 * Date : 1ST OCTOBER,2025
 * ==================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* thread_function(void* arg) {
    int id = *(int*)arg;
    printf("Inside thread %d\n", id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3];


    for (int i = 0; i < 3; i++) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &ids[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }


    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}
/*==============================================================================
 * Output:
  varun@varun:~/handson_2$ cc 6.c
varun@varun:~/handson_2$ ./a.out
Inside thread 1
Inside thread 2
Inside thread 3
*/
