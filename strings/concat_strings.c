#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* return_user_input();
char* concat_strings(char* string1, char* string2);

int main() {
	char *first_string = return_user_input();
	char *second_string = return_user_input();
	char *combined_string = concat_strings(first_string, second_string);
	printf("%s\n", combined_string);
	free(first_string);
	free(second_string);
	free(combined_string);
	return 0;
}

char *return_user_input() {
	printf("Please enter the first string: ");
	char* user_string = malloc(sizeof(char) * 100);
	if (user_string == NULL) {
		printf("Memory allocation failed!\n");
		return NULL;
	}
	fgets(user_string, 100, stdin);
	user_string[strcspn(user_string, "\n")] = '\0';
	return user_string;
}

char* concat_strings(char* string1, char* string2) {
	char* combined_string = malloc(strlen(string1) + strlen(string2) + 1);
	for (int i = 0; i < strlen(string1); i++) {
		combined_string[i] = string1[i];
	}
	int j = strlen(string1);
	int i = 0;
	while (i < strlen(string2)) {
		combined_string[j] = string2[i];
		i += 1;
		j += 1;
	}

	combined_string[j] = '\0';
	return combined_string;
}
