// 1. Write the code ( executable statements ) to fill the array square with the identity matrix.
#include <stdio.h>
#include <math.h>

int main() {
	int identity[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) {
				identity[i][j] = pow(i + 1, 2);
			}
			else {
				identity[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d", identity[i][j]);
		}
		printf("\n");
	}
	return 0;
}