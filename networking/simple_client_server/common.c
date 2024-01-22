#include "common.h"

int create_unix_domain_socket() {
	int server_fd;

	// Create the socket
	server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (server_fd < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	return server_fd;
}

struct sockaddr_un prepare_unix_domain_socket_address(int server_fd, const char *filename) {
	struct sockaddr_un name;

	// Prepare a name for the socket
	name.sun_family = AF_LOCAL;
	strncpy(name.sun_path, filename, sizeof(name.sun_path));
	name.sun_path[sizeof(name.sun_path) - 1] = '\0';
	
	return name;
}

size_t compute_size(struct sockaddr_un name) {
	size_t size;
	size = offsetof(struct sockaddr_un, sun_path) + strlen(name.sun_path);
	return size;
}
