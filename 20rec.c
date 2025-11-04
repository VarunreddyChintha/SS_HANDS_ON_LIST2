/*
============================================================================
Name : 20rec.c
Author : CHINTHA JOGGARI VARUN REDDY
Description :reciever Program so that both can communicate by FIFO .
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

    int fd = open(fifo, O_RDONLY);
    if (fd == -1) { perror("open"); exit(1); }

    char buf[100];
    int n;
    while ((n = read(fd, buf, sizeof(buf)-1)) > 0) {
        buf[n] = '\0';
        if (strcmp(buf, "x") == 0) break;
        printf("Received: %s\n", buf);
    }

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
varun@varun:~/hands_on2$ cc 20rec.c
varun@varun:~/hands_on2$ ./a.out
Received: Hi ra
Received: I sent msg
============================================================================
*/
