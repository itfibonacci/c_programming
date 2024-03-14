#include <stdio.h>
#include <stdarg.h>

int add_multiple_values(int argcount, ...);

int main() {
	printf("The sum of 14, 22 and 24 is: %d\n", add_multiple_values(3, 14, 22, 24));
}

int add_multiple_values(int argcount, ...) {
	int total = 0;

	// Declare a variable of type va_list
	va_list argptr;

	// Initialize the argptr variable
	va_start(argptr, argcount);

	for (unsigned char i = 0; i < argcount; i++) {
		total += va_arg(argptr, int);
	}

	// End use of the argptr variable
	va_end(argptr);

	return total;
}
