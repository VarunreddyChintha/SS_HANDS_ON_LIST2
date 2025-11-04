/*
============================================================================
Name : 34b.c
Author : CHINTHA JOGGARI VRAUN REDDY
Description : TCP server handling multiple clients concurrently using pthreads
Date: 1ST OCTOBER, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUF_SIZE 1024

void *handle_client(void *arg) {
    int client_sock = *(int *)arg;
    free(arg);

    char buffer[BUF_SIZE];
    int n;

    while ((n = read(client_sock, buffer, BUF_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("Client says: %s", buffer);
        write(client_sock, buffer, n);  // echo back
    }

    close(client_sock);
    return NULL;
}

int main() {
    int server_fd, *client_sock;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen
    if (listen(server_fd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept clients
    while (1) {
        client_sock = malloc(sizeof(int));
        *client_sock = accept(server_fd, (struct sockaddr *)&address, &addr_len);
        if (*client_sock < 0) {
            perror("accept failed");
            free(client_sock);
            continue;
        }

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client_sock);
        pthread_detach(tid); // free resources automatically
    }

    close(server_fd);
    return 0;
}

/*
============================================================================
OUTPUT:
varun@varun:~/handson_2$ cc 34b.c -lpthread
varun@varun:~/handson_2$ ./a.out
Server listening on port 8080...

//OPEN OTHER TERMINALS AND TYPE nc localhost 8080  TO CONNECT TO THIS SERVER
//TYPE YOUR MSG ,THEN CLIENT RECIEVES IT.
Client says: hi frm c1
Client says: hi from c2
Client says: from c1
Client says: from c3

============================================================================
*/


