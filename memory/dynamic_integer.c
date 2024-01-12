#include <stdlib.h>
#include <stdio.h>

int main() {
	int *num;
	int **ptr = &num;

	*ptr = malloc(sizeof(int));
	**ptr = 42;

	printf("The value of num is: %d\n", **ptr);
	free(*ptr);
	return 0;
}
