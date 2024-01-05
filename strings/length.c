#include <stdio.h>

int stringlen(char *word);

int main() {

	while (1) {
		char user_input[50];
		printf("Please type the word to get the length: ");
		scanf("%49s", user_input);
		printf("%d\n", stringlen(user_input));
	}
}

int stringlen(char *word) {
	int i = 0;
	while(1) {
		char current_char = *(word+i);
		if (current_char == '\0') {
			break;
		}
		i += 1;
	}
	return i;
}
