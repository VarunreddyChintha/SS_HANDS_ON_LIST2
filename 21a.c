/*
============================================================================
Name : 21a.c
Author : CHINTHA JOGGARI VARUN REDDY
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

    // Create FIFOs if not exist
    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    int fd_write = open(fifo1, O_WRONLY);
    int fd_read = open(fifo2, O_RDONLY);

    char msg[100], buffer[100];

    printf("Chat started (type 'x' to exit)\n");

    while (1) {
        // Send message
        printf("A: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0; // remove newline
        write(fd_write, msg, strlen(msg)+1);
        if (strcmp(msg, "x") == 0)
            break;

        // Receive message
        int n = read(fd_read, buffer, sizeof(buffer));
        buffer[n] = '\0';
        if (strcmp(buffer, "x") == 0)
            break;
        printf("B: %s\n", buffer);
    }

    close(fd_write);
    close(fd_read);

    // Delete FIFOs
    unlink(fifo1);
    unlink(fifo2);

    printf("Chat ended.\n");
    return 0;
}
/*
============================================================================
OUTPUT:

varun@varun:~/handson_2$ cc 21a.c -o ./test21a
varun@varun:~/handson_2$ ./test21a
Chat started (type 'x' to exit)
A: hi ra
B: how are you
A: Im fine 
B: Ok bye
A: x
Chat ended.
============================================================================
*/
