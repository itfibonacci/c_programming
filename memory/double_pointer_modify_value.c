#include <stdio.h>

void modify_value (int **ptr);

int main() {
	int num = 15;
	printf("Num is: %d", num);
	int* addr_num = &num;
	modify_value(&addr_num);
	printf("\nNum is: %d", num);
	return 0;
}

void modify_value (int **ptr) {
	**ptr = 20;
}