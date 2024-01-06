#include <stdio.h>

int main() {
	printf("%zu", sizeof(123));
	printf("\n%zu", sizeof(31231121223123123));
	printf("\n%zu", sizeof(31231121223123123.123));
	printf("\nSize of char is: %zu", sizeof(char));
	printf("\nSize of double is: %zu", sizeof(double));
	printf("\nSize of float is: %zu", sizeof(float));
	return 0;
}
