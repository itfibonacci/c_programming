#include <stdio.h>

int main(void) {
	#define BUFFER_SIZE 1024;

	char buffer[BUFFER_SIZE];

	FILE *fp = fopen("file.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
		// Process the data in the buffer
	}

	fclose(fp);


}