#include <stdio.h> // for putchar

int my_printf(char *format, ...);

int main() {
	my_printf("hello soul!");
	my_printf("123");;
}

int my_printf(char *format, ...) {
	int count = 0;

	while(*format != '\0') {
		
		
		putchar(*format);
		format += 1;
		count += 1;
	}
	putchar('\n');
	return count;
}
