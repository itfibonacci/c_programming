#include <stdio.h>
#include <stdlib.h>

void read_file_fgets (char* file_path);
void print_hex (char* file_path);

int main() {
	read_file_fgets("135-0.txt");
	print_hex("135-0.txt");
	return 0;	
}

void read_file_fgets (char* file_path) {
	FILE* text_file = fopen(file_path, "r, ccs");
	if (text_file == NULL) {
		printf("Could not open the file.\n");
		exit(-1);
	}

	char line[256];
	if (fgets(line, sizeof(line), text_file) != NULL) {
		printf("Read from file: %s", line);
	}
	else {
		printf("Error reading from a file.\n");
	}
	fclose(text_file);
}

void print_hex (char* file_path) {
	FILE* text_file = fopen(file_path, "r");
	if (text_file == NULL) {
		printf("Could not open the file.\n");
		exit(-1);
	}
	char line[256];
	if (fgets(line, sizeof(line), text_file) != NULL) {
		for (int i = 0; line[i] != '\0'; i++) {
			printf("%02X ", (unsigned char)line[i]);
		}
		printf("\n");
	}
	else {
		printf("Error reading from a file.\n");
	}
	fclose(text_file);

}
