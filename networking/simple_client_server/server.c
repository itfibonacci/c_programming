#include <sys/un.h>
#include <stddef.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define LISTEN_BACKLOG 50

int create_unix_domain_socket();
int bind_unix_domain_socket(int sock, const char *filename);
void start_listening(int socket);
int accept_connection(int server_fd);
void cleanup();

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

int create_unix_domain_socket() {
	int server_fd;

	// Create the socket
	server_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
	if (server_fd < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	return server_fd;
}

int bind_unix_domain_socket(int server_fd, const char *filename) {
	struct sockaddr_un name;
	size_t size;
	
	// unlink any existing socket file
	unlink(filename);

	// Bind a name to the socket
	name.sun_family = AF_LOCAL;
	strncpy(name.sun_path, filename, sizeof(name.sun_path));
	name.sun_path[sizeof(name.sun_path) - 1] = '\0';
	
	size = offsetof(struct sockaddr_un, sun_path) + strlen(name.sun_path);
	if (bind(server_fd, (struct sockaddr *) &name, size ) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}
	return server_fd;
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
