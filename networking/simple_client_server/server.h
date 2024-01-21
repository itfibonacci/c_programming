#define LISTEN_BACKLOG 50

void start_listening(int socket);
int accept_connection(int server_fd);
void cleanup();
