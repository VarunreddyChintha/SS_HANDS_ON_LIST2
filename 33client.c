/*
============================================================================
Name : 33client.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : TCP client to communicate with a server on another machine
Date: 1ST October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Enter server IP address here
    if(inet_pton(AF_INET,"127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");

    // Receive message from server
    read(sock, buffer, 1024);
    printf("Server says: %s\n", buffer);

    close(sock);
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ nano 33client.c
varun@varun:~/handson_2$ cc 33client.c
varun@varun:~/handson_2$ ./a.out
Message sent to server.
Server says: Hello from server
============================================================================
*/
