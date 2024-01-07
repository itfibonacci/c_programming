#include <stdio.h>

int char_to_int (char input_char);
char int_to_char (int input_int);
char next_char (char input_char);

int main() {
	printf("%d", char_to_int('l'));
	printf("\n%c", int_to_char(12));
	printf("\n%c", int_to_char(22));
	printf("\n%c", next_char('g'));
	printf("\n%c", next_char(45));
	printf("\n%c", next_char(99));
	return 0;
}

int char_to_int (char input_char) {
	return input_char;
}

char int_to_char (int input_int) {
	return input_int;
}

char next_char (char input_char) {
	return input_char+1;
}

