#include <stdio.h>
#include <stdlib.h>

int* get_user_array(int length);

int main() {
	int user_length;
	printf("Please a size to create your array:");
	scanf("%d", &user_length);
	int *user_array = get_user_array(user_length);
	for (int i = 0; i < user_length; i++) {
		printf("%d", *(user_array + i));
	}
	printf("\n");
	return 0;
}

int* get_user_array(int length) {
	int *user_array = malloc(sizeof(char) * length);
	for (int i = 0; i < length; i++) {
		*(user_array + i) = i;
	}
	return user_array;
}