#include <stdio.h>

int main() {
	//char mystring[] = "abc";
	//printf("%zu", strlen(mystring));
	int x = 5;
	int *pointer_of_x = &x;
	printf("The address of x is: %p\n", &x);
	printf("The value of x is: %d\n", *&x);
	printf("The value of x is: %d\n", *pointer_of_x);
}
