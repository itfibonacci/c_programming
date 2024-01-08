#include <stdio.h>
#include <stdlib.h>

int main() {
	int* my_array = malloc(sizeof(int) * 5);
	size_t size_my_array = 5;
	if (my_array == NULL) {
		return 1;
	}
	printf("Initial array: ");
	for (int i = 0; i < size_my_array; i++) {
		*(my_array + i) = i;
		printf("%d", *(my_array + i));
	}
	my_array = realloc(my_array, sizeof(int) * 10);
	size_my_array = 10;
	if (my_array == NULL) {
		return 1;
	}
	printf("\nExpanded array: ");
	for (int i = 0; i < size_my_array; i++) {
		my_array[i] = i;
		printf("%d", *(my_array + i));
	}
	my_array = realloc(my_array, sizeof(int) * 5);
	if (my_array == NULL) {
		return 1;
	}
	size_my_array = 5;
	printf("\nShrunk array: ");
	for (int i = 0; i < size_my_array; i++) {
		printf("%d", my_array[i]);
	}
	free(my_array);
	return 0;
}
