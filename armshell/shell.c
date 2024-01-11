#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void armshloop();
char* armsh_read_line();
char* armsh_split_line(char* line);
bool armsh_execute(char* args);

int main(int argc, char **argv) {
	armshloop();
	return EXIT_SUCCESS;
}

// the shell during its loop should
// read - read from std input
// parse - separate the command string into a program and arguments
// execute - run the parsed command

void armshloop() {
	char *line;
	char **args;
	int status;
	do {
		printf("🇦🇲: ");
		line = armsh_read_line();
		args = armsh_split_line(line);
		status = armsh_execute(args);

		free(line);
		free(args);
	} while (status);		
}