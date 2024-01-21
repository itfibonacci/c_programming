#include <sys/un.h>
#include <stddef.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int create_unix_domain_socket();
int bind_unix_domain_socket(int sock, const char *filename);
