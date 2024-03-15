#include <stdio.h> // for putchar
#include <stdarg.h> // for variadic functionality
#include <stdlib.h> // for malloc
#include <math.h> // for log function to determine count of digits in an int

const char *missing_format_err_msg = "warning: incomplete format specifier\n";	

int my_printf(char *format, ...);
char *int_to_string(int num); // helper to convert an integer of arbitrary length into a string

int main() {
	//my_printf("hello soul!");
	//my_printf("123");
	my_printf("123%%");
	my_printf("123%% hello buddy");	

	my_printf("123 bylah %s buddy %s %s", "Hello", "my ferend", "ferend123");

	// lets try printing a char
	my_printf("Hello char %c buddy, another char %c", 'y', 'f');

	// lets try printing a char and and s
	my_printf("Hello char: %c buddy, another char: %c and a string: %s", 'y', 'f', "hello bud");
	
	// lets try printing a decimal
	my_printf("print integer: %i", 12);
	my_printf("print integers: %i, %i, %i", 12, 123123213, 1235873418561372512);


	//printf("Result is %s", int_to_string(123));
	
	// add below to tests
	//printf("Return for 123%% is: %d\n", my_printf("123%"));
	//printf("Hello darkness %");
}

int my_printf(char *format, ...) {
	int count = 0;

	// Declare a variable of type va_list
	va_list argptr;

	// Initialize the argptr variable
	va_start(argptr, format);

	while(*format != '\0') {
		if (*format == '%') {
			switch (*(format + 1)) {
				case '%':
					// %% means escaping %, so we should print one %
					putchar('%');
					break;
				case 's':
					fputs(va_arg(argptr, char*), stdout);
					break;
				case 'c':
					putchar(va_arg(argptr, int));
					break;
				case 'i':
				{
					fputs(int_to_string(va_arg(argptr, int)), stdout);
					break;
				}
				default:
					fputs(missing_format_err_msg, stderr);
					return 0;
					break;
			}
			format += 2;
			continue;
		}
		
		putchar(*format);
		format += 1;
		count += 1;
	}

	// End use of the argptr variable
	va_end(argptr);

	putchar('\n');
	return count;
}

char *int_to_string(int num) {
	int digits_count = log10(num) + 1;
 	size_t size = sizeof(char) * digits_count + 1;
	char *num_s = malloc(size);
	int count;
	
	for (count = 0; count < digits_count; count++) {
		num_s[digits_count - count - 1] = (num % 10) + '0';
		num = num / 10;
	}

	num_s[digits_count] = '\0';
	return num_s;
}
