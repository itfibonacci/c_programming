#include <stdio.h>

/*
Change Value of Array Elements Change the value of the third and fifth elements of your array to -1 and 0, respectively.
*/

int change_index ( int arr[], int len, int index, int value );

int main() {
	int my_nums[] = {4, 5, 5, 2, 123, 222};
	int len_my_nums = sizeof(my_nums) / sizeof(int);
	//for (i = 0; i )
	change_index( my_nums, len_my_nums, 4, 12 );
	//change_index( my_nums, len_my_nums, 12, 12 );
	//change_index( my_nums, len_my_nums, 4, 12 );
	return 0;
}

int change_index ( int arr[], int len, int index, int value ) {
	printf("Array before the change is");
	for (int i = 0; i < len; i++) {
		printf("\nElement %d: %d", i, *(arr+i));
	}
	if (index > len - 1) {
		printf("Out of bounds change. Array length is: %d but you requested index:%d", len, index);
		return 1;
	}
	*(arr + index) = value;
	printf("\nArray after the change is");
	for (int i = 0; i < len; i++) {
		printf("\nElement %d: %d", i, *(arr+i));
	}
	return 0;
}