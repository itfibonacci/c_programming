#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
	char mystring[] = "helloworld";
	int *my_pointer = malloc(10*sizeof(int));
	printf("Memory address: %p", my_pointer);
	return 0;
}
