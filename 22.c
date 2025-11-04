/*
============================================================================
Name : 22.c
Author : CHINTHA JOGGARI VARUN REEDY
Description :C-program to wait for data to be written into FIFO within 10 sec
using select sys with fifo.
Date: 1ST OCTOBER, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
    const char *fifo_path = "./fifo22";


    int fd = open(fifo_path, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fd_set readfds;
    struct timeval timeout;
    char buffer[100];

    printf("Waiting for data for 10 seconds...\n");

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("Timeout! No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            int n = read(fd, buffer, sizeof(buffer));
            if (n > 0) {
                buffer[n] = '\0';
                printf("Data received: %s\n", buffer);
            }
        }
    }

    close(fd);
    return 0;
}
/*

============================================================================

OUTPUT:

varun@varun:~/handson_2$ nano 22.c
varun@varun:~/handson_2$ cc 22.c
varun@varun:~/handso_2$ ./a.out
Waiting for data for 10 seconds...

varun@varun:~/handson_2$ echo "hi" >> fifo22

Data received: hi

varun@varun:~/handson_2$ ./a.out
Waiting for data for 10 seconds...
Timeout! No data received within 10 seconds.

============================================================================

*/
