#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file;
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	file = fopen("address.txt", "r");
	if (file == NULL)
	{
		printf("Could not open the file.");
		return 1;
	}

	buffer = (char *)malloc(bufsize * sizeof(char));
	characters = getline(&buffer, &bufsize, file);
	printf("%zu characters were read. \n", characters);
	
	return 0;
}