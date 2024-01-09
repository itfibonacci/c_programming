#include <stdio.h>
// pass a string with leading and ending whitespace
// return the string without any whitespace

char *strip (char *tobestripped);

int main() {
	printf("     asdasda   ");
	printf("\n%s", strip("   asdasdas   "));
	return 0;
}

char *strip (char *tobestripped) {
	int i = 0;
	int stripped_length = 0;
	while (*(tobestripped+i) != '\0') {
		if (*(tobestripped+i) != ' ') {
			stripped_length += 1;
		}
		i += 1;
	}
	i = 0;
	int j = 0;
	char stripped_string[stripped_length+1];
	while (*(tobestripped+i) != '\0') {
		if (*(tobestripped+i) != ' ') {
			stripped_string[j] = *(tobestripped+i);
			j += 1;
		}
		i += 1;
	}
	stripped_string[j] = '\0';
	return stripped_string;
}
