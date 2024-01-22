#define LISTEN_BACKLOG 50

int bind_unix_domain_server_socket(int server_fd, struct sockaddr_un name, size_t size);
void start_listening(int socket);
int accept_connection(int server_fd);
void cleanup();
