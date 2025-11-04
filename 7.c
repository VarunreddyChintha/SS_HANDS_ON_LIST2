/*===================================================================================
 * Name: 7.c
 * Author : CHINTHA JOGGARI VARUN REDDY
 * Description:  Write a simple program to print the created thread ids.
 * Date : 1ST OCTOBER,2025
 * ==================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_handler(void *args){
	printf("The thread id is %lu\n", (unsigned long)pthread_self());
}

int main(){
	pthread_t thread;
	pthread_create(&thread,NULL,thread_handler,NULL);
	 pthread_create(&thread,NULL,thread_handler,NULL);
	  pthread_create(&thread,NULL,thread_handler,NULL);
	pthread_join(thread,NULL);
}

/*==============================================================================
 * Output:
  varun@varun:~/handson_2$ cc 7.c
varun@varun:~/handson_2$ ./a.out
The thread id is 130233944504000
The thread id is 130233936111296
The thread id is 130233927718592
*/
