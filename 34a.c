/*
============================================================================
Name : 34a.c
Author : CHINTHA JOGGARI VARUN REDDY
Description : TCP server handling multiple clients concurrently using fork()
Date: 1ST October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define BUF_SIZE 1024

void handle_client(int client_sock) {
    char buffer[BUF_SIZE];
    int n;
    while ((n = read(client_sock, buffer, BUF_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("Client: %s", buffer);
        write(client_sock, buffer, n);  // echo back
    }
    close(client_sock);
    exit(0);
}

int main() {
    int server_fd, client_sock;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(server_fd, 5);
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_sock = accept(server_fd, (struct sockaddr *)&address, &addr_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        if (fork() == 0) {  // child process
            close(server_fd);
            handle_client(client_sock);
        }
        close(client_sock);  // parent closes copy
    }
}


/*
============================================================================
OUTPUT :
varun@varun:~/handson_2$ nano 34a.c
varun@varun:~/handson_2$ cc 34a.c
varun@varun:~/handson_2$ ./a.out

Server listening on port 8080...

//OPEN OTHER TERMINALS AND TYPE nc localhost 8080  TO CONNECT TO THIS SERVER
//TYPE YOUR MSG ,THEN CLIENT RECIEVES IT.


Client: Hi from client 1
Client: hi client2
Client: hi
Client: hi from c3



============================================================================
*/
