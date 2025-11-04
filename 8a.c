/*==================================================================
 * Name : 8a.c
 * Author : CHINTHA JOGGARI VARUN REDDY
 * Description: 8. Write a separate program using signal system call to catch the following signals.
   a. SIGSEGV
 * Date: 1st October,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>


void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}
int main(){
	signal(SIGSEGV,handler);

	int n;
	printf("Enter a value \n");
	scanf("%d",n);
}

/*====================================
 * Output:
varun@varun:~/handson_2$ cc 8a.c
8a.c: In function ‘main’:
8a.c:21:17: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Wformat=]
   21 |         scanf("%d",n);
      |                ~^  ~
      |                 |  |
      |                 |  int
      |                 int *
varun@varun:~/handson_2$ ./a.out
Enter a value
1
signal caught 11 : Segmentation fault */
