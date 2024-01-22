#include "common.h"
#include "server.h"

int main() {
	// This will be used as a buffer to read client string to
	char buf[256];
	// Register the cleanup function to be called at exit
	int server_fd = create_unix_domain_socket();
	// Unlink any existing socket file
	unlink(SOCKET_FILENAME);
	struct sockaddr_un socket_address = prepare_unix_domain_socket_address(server_fd, SOCKET_FILENAME);
	size_t size_server_socket = compute_size(socket_address);
	server_fd = bind_unix_domain_server_socket(server_fd, socket_address, size_server_socket);
	start_listening(server_fd);
	int clientfd = accept_connection(server_fd);
	ssize_t nbytes = read(clientfd, buf, 255);
	if (nbytes < 0) {
		perror("Reading went wrong.");
	}
	buf[nbytes] = '\0';
	printf("Server received this: (%s) from client.\n", buf);
	close(clientfd);
	close(server_fd);
	return 0;
}

int bind_unix_domain_server_socket(int server_fd, struct sockaddr_un name, size_t size) {
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
