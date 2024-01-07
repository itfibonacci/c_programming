#include <stdio.h>
#include <stdlib.h>

char* copy_string(char *string_to_copy);

int main() {
	char *copied_string = copy_string("Hello World!");
	printf("%s", copied_string);
	return 0;
}

char* copy_string(char *string_to_copy) {
	int i = 0;
	while (*(string_to_copy+i) != '\0') {
		i += 1;
	}
	int string_length = i;
	char *copied_string = malloc(sizeof(char) * (string_length + 5));
	i = 0;
	while (i < string_length) {
		*(copied_string + i) = *(string_to_copy + i);
		i += 1;
	}
	*(copied_string + i) = 'c';
	*(copied_string + i + 1) = 'o';
	*(copied_string + i + 2) = 'p';
	*(copied_string + i + 3) = 'y';
	*(copied_string + i + 4) = '\0';
	return copied_string;
}