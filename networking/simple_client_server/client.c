#include "common.h"
#include "client.h"

int main() {
	int client_fd = create_unix_domain_socket();
	struct sockaddr_un socket_address = prepare_unix_domain_socket_address(client_fd, SOCKET_FILENAME);
	size_t size_client_socket = compute_size(socket_address);
	connect_client_socket(client_fd, socket_address, size_client_socket);
	write(client_fd, "abc", 4);
	close(client_fd);
	return 0;	
}

int connect_client_socket(int client_fd, struct sockaddr_un socket_address, size_t size_client_socket) {
	if (connect(client_fd, (struct sockaddr *) &socket_address, size_client_socket) != 0) {
		perror("Client socket");
		return -1;
	}
	else {
		printf("The connection has been established\n");
		return 0;
	}
}
