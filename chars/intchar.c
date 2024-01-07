#include <stdio.h>

int char_to_int (char input_char);
char int_to_char (int input_int);
char next_char (char input_char);
char next_nth_char (char input_char, int step);
char to_upper (char lowercase_char);

int main() {
	printf("%d", char_to_int('?'));
	printf("\n%c", int_to_char(12));
	printf("\n%c", int_to_char(22));
	printf("\n%c", next_char('g'));
	printf("\n%c", next_char(45));
	printf("\n%c", next_char(99));
	printf("\n%c", next_nth_char('a', 222));
	printf("\n%c", to_upper('a'));
	printf("\n%c", to_upper('B'));
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

char next_nth_char (char input_char, int step) {
	return input_char+step;
}

char to_upper (char lowercase_char) {
	if (lowercase_char < 97 || lowercase_char > 122) {
		// this case is when we don't pass a lowercase char
		return lowercase_char;
	}
	return lowercase_char-32;
}
