/*
============================================================================
Name : 21b.c
Author : CHINTHA JOGGGARI VARUN REDDY
Description :C-program to two way communication using fifo.
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *fifo1 = "./fifo_a_to_b"; // A → B
    const char *fifo2 = "./fifo_b_to_a"; // B → A

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    int fd_read = open(fifo1, O_RDONLY);
    int fd_write = open(fifo2, O_WRONLY);

    char msg[100], buffer[100];

    printf("Chat started (type 'x' to exit)\n");

    while (1) {

        int n = read(fd_read, buffer, sizeof(buffer));
        buffer[n] = '\0';
        if (strcmp(buffer, "x") == 0)
            break;
        printf("A: %s\n", buffer);


        printf("B: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0;
        write(fd_write, msg, strlen(msg)+1);
        if (strcmp(msg, "x") == 0)
            break;
    }

    close(fd_write);
    close(fd_read);


    unlink(fifo1);
    unlink(fifo2);

    printf("Chat ended.\n");
    return 0;
}
/*
============================================================================
OUTPUT:

varun@varun:~/handson_2$ cc 21b.c -o ./test21b
varun@varun:~/handson_2$ ./test21b
Chat started (type 'x' to exit)
A: hi ra
B: how are you
A: Im fine 
B: Ok bye
Chat ended.
============================================================================
*/
