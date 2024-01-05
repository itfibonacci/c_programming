#include <stdio.h>

int main() {
	char mystr[] = "Hello World!";
	char mystring[10] = "hey";
	
	int i = 0;
	while (mystring[i] != '\0')
	{
		printf("Character: %c, Address: %p\n", mystring[i], &mystring[i]);
		i += 1;
	}

	return 0;
}
