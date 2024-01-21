#include <sys/un.h>
#include <stddef.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "server.h"

int main() {
	// Register the cleanup function to be called at exit
	int server_fd = create_unix_domain_socket();
	bind_unix_domain_socket(server_fd, "/tmp/socketing");
	start_listening(server_fd);
	int clientfd = accept_connection(server_fd);
	atexit(cleanup);
	return 0;
}

void cleanup() {

}

void start_listening(int server_fd) {
	if (listen(server_fd, LISTEN_BACKLOG) == -1) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

int accept_connection(int server_fd) {
	int client_fd;
	struct sockaddr_un client_addr;
	socklen_t client_addr_size;
	
	client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_size);

	if (client_fd == -1) {
		perror("Client socket:");
	}
	return client_fd;
}
