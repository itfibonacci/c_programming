#include <stdio.h>
#include <string.h>

int main() {
	char mystring[50] = "Hello World";
	printf("%lu", strlen(mystring));
	printf("\n%lu", sizeof(mystring));
	return 0;
}