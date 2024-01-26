/* 
strrchr
Purpose: Locate the last occurrence of a character in a string.
Prototype: char *strrchr(const char *s, int c);
*/

#include <stdio.h>

char *my_strchr(const char *string, char ch);

int main() {
	char my_str[] = "HelloWorld";
	for (int i = 0; my_str[i] != '\0'; i++){
		printf("The address of %c are: %p\n", my_str[i], &my_str[i]);
	}
	printf("The last occurence is at: %p\n", my_strchr(my_str, 'o'));
	char *my_null = NULL;
	printf("The last occurence is at: %p\n", my_strchr(my_null, 'x'));
	return 0;
}

char *my_strchr(const char *string, char ch) {
	char *last_occurence_ptr = NULL;

	int i = 0;
	while (string[i] != '\0'){
		if (string[i] == ch){
			last_occurence_ptr = (char *)&string[i];
		}
		i++;
	}
	return last_occurence_ptr;
}
