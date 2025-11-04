/*
============================================================================
Name : 20sender.c
Author : CHINTHA JOGGARI VARUN  REDDY
Description :Sender Program so that both can communicate by FIFO .
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char *fifo = "myfifo";
    mkfifo(fifo, 0666);

    int fd = open(fifo, O_WRONLY);
    if (fd == -1) { perror("open"); exit(1); }

    char msg[100];
    while(1) {
        printf("Enter message (press x to exit): ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0'; 
        if (strcmp(msg, "x") == 0) break;
        write(fd, msg, strlen(msg));
    }

    write(fd, "x", 1);
    close(fd);
    return 0;

}
/*
============================================================================
OUTPUT :

varun@varun:~/handson_2$ cc 20sender.c
varun@varun:~/handson_2$ ./a.out
Enter message (press x to exit): Hi ra
Enter message (press x to exit): I sent msg
Enter message (press x to exit): x

Terminal 2:
varun@varun:~/handson_2$ ./a.out
Received: Hi ra
Received: I sent msg
============================================================================
*/
