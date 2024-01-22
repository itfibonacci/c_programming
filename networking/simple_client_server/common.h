#include <sys/un.h>
#include <stddef.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define SOCKET_FILENAME "/tmp/socketing"

int create_unix_domain_socket();
struct sockaddr_un prepare_unix_domain_socket_address(int server_fd, const char *filename);
size_t compute_size(struct sockaddr_un name);
