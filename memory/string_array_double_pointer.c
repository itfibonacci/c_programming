#include <stdio.h>

int main() {
	char *names[] = {"Alice", "Bob", "Kate", "Syuzi"};
	
	for (int i = 0; i < 4; i++) {
		printf("\nAddress of %d-th element is: %p", i, *(names + i));
		printf("\nElement of %d-th element is: %c", i, **(names + i));
	}
	return 0;
}