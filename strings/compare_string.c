#include <stdbool.h>
#include <stdio.h>

bool string1_greater_string2 ( char* str1, char* str2 );

int main() {
	char mystring1[] = "hello world!12121";
	char mystring2[] = "hello world!";
	printf("%d", string1_greater_string2(mystring1, mystring2));
	return 0;
}

bool string1_greater_string2 ( char* str1, char* str2 ) {
	int i = 0;

	while (*(str1 + i) != '\0') {
		i += 1;
	}

	int length1 = i;
	i = 0;

	while (*(str2 + i) != '\0') {
		i += 1;
	}
	int length2 = i;

	if (length1 > length2) {
		return true;
	}
	else {
		return false;
	}	
}