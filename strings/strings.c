#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void string_print (char* my_str);
char* string_add(char* my_str);

int main() {
	char mystr[MAX_LENGTH] = "Hello World!";
	string_print(mystr);	
	printf("\n%s", string_add(mystr));
	return 0;
}

void string_print (char* my_str) {
	int i = 0;
	while (my_str[i] != '\0')
	{
		printf("Character: %c, Address: %p\n", my_str[i], &my_str[i]);
		i += 1;
	}
}

char* string_add(char* my_str) {
	strcat(my_str, "copy");
	return my_str;
}
