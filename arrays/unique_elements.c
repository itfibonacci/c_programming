#include <stdio.h>
#include <stdlib.h>
/* Write a function that removes duplicate elements from an array and returns a new array with unique elements. */

int *unique_elements(int arr[], int size, int *new_size);

int main() {
	int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 12, 221, 12, 33, 111};
	int size = 10;
	int new_size = 0;
	int *unique_arr = unique_elements(arr, size, &new_size);
	printf("The unique elements size is: %d\n", new_size);
	int i = 0;
	while (i < new_size) {
		printf("The new arrays %d-th element is: %d\n", i, unique_arr[i]);
		i++;
	}
	free(unique_arr);
	return 0;	
}

#define UNIQUE_SIZE 5

int *unique_elements(int arr[], int size, int *new_size) {
	int position = 0;
	size_t unique_size = UNIQUE_SIZE;
	int *unique_arr = (int *) malloc(unique_size * sizeof(int));

	for (int i = 0; i < size; i++){
		char is_unique = 0;
		for (int j = 0; j < size; j++){
			if (i == j) {
				continue;
			}
			if (arr[i] == arr[j]){
				is_unique = 1;
			}
		}
		if (is_unique == 0) {
			if (position > unique_size) {
				unique_size += 10;
				unique_arr = realloc(unique_arr, unique_size * sizeof(int));  
			}
			unique_arr[position] = arr[i];
			position++;
			*new_size = *new_size + 1;
		}
	}
	return unique_arr;
}
