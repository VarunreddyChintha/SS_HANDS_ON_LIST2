/*
============================================================================
Name : 33server.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : TCP server to communicate with a client on another machine
Date: 1st October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Hello from server";

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // listen on all interfaces
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // Accept connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                             (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    read(new_socket, buffer, 1024);
    printf("Client says: %s\n", buffer);

    // Send message to client
    send(new_socket, message, strlen(message), 0);
    printf("Message sent to client.\n");

    close(new_socket);
    close(server_fd);
    return 0;
}
/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 33server.c
varun@varun:~/handson_2$ ./a.out
Server listening on port 8080...
Client says: Hello from client
Message sent to client.

============================================================================
*/
