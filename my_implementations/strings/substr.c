#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
Create a function that extracts a substring from a given string, based on the starting index and length.
- Can add support for negative lengths
- Can add support for negative start index
*/
char *my_substr(const char *str, int start, int length);

int main() {
	char *substring1 = my_substr("Helloworld", 2, 3);
	printf("My substring is: %s\n", substring1);

	char *substring2 = my_substr("Helloworld", 1, 0);
	printf("My substring is: %s\n", substring2);

	char *substring3 = my_substr("Helloworld", 10, 1);
	printf("My substring is: %s\n", substring3);
	
	char *substring4 = my_substr("", 10, 1);
	printf("My substring is: %s\n", substring4);

	char *substring5 = my_substr("HelloWorld", 3, 1);
	printf("My substring is: %s\n", substring5);
	
	free(substring1);
	free(substring2);
	free(substring3);
	free(substring4);
	free(substring5);
	
	return 0;
}

char *my_substr(const char *str, int start, int length){
	size_t str_len = strlen(str);
	if (start > str_len - 1){
		return NULL;
	}
	if (str_len == 0){
		return NULL;
	}
	char *my_substr = malloc(length + 1);
	int i = 0;
	while (str[i + start] != '\0' && i < length){
		my_substr[i] = str[i + start];
		i++;
	}
	my_substr[i] = '\0';
	return my_substr;
}
