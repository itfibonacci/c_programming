#include <stdio.h>

char* print_string(char *word);

int main() {
	char *mychar = "Hello World";
	char mychar1[12] = "Hello World";
	printf("%s", mychar1);
	printf("%s", print_string("Hello World"));
	printf("\n%c", *mychar);
	printf("\n%p", mychar);
}

char* print_string(char *word) {
	return word;
}