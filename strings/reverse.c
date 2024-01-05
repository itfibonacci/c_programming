#include <stdio.h>
#include <string.h>

void reverse(char* word);

int main() {
	char str[] = "Hello Worlds!";
	reverse(str);
}

void reverse(char word[]) {
	int length = strlen(word);
	char reverse_word[length+1];
	int j = 0;
	
	for (int i = length - 1; i >= 0; i--) {
		reverse_word[j] = word[i];
		j += 1;
	}
	reverse_word[j] = '\0';
	printf("%s", reverse_word);
}