#include "common.h"

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
