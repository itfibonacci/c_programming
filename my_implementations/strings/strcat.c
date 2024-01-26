#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrcat (char *string1, char *string2);

int main() {
	char *conc_string = mystrcat("Hello", "World");
	printf("The concatenated string is: %s\n", conc_string);
	free(conc_string);
	conc_string = mystrcat("aaaHello", "World");
	printf("The concatenated string is: %s\n", conc_string);
	free(conc_string);
	return 0;
}

char *mystrcat (char *string1, char *string2){
	size_t len1 = strlen(string1);
	size_t len2 = strlen(string2);

	char *concatenated_string = malloc(len1 + len2 + 1);
	if (concatenated_string == NULL) {
		printf("Allocation failed.");
		exit(1);
	}
	size_t i = 0;
	while (string1[i] != '\0'){
		concatenated_string[i] = string1[i];
		i++;
	}
	i = 0;
	while (string2[i] != '\0'){
		concatenated_string[i+len1] = string2[i];
		i++;
	}
	concatenated_string[len1 + len2] = '\0';
	return concatenated_string;
}
