#include <stdio.h>

int power(int num, int power);
int tetration(int base, int exponent);

int main() {
	power(2,4);
	power(3,4);
	power(3,1);
	power(3,0);
	power(27,1);
	tetration(2,3);
	tetration(3,3);
	tetration(3,4);
	tetration(3,5);
	tetration(3,7);
	return 0;
}

int power(int num, int power) {
	int i = 1;
	int result;
	if (power == 0) {
		result = 1;
	}
	else {
		result = num;
		while (i < power) {
			result = result * num;
			i += 1;
		}
	}
	printf("Num: %d to power %d is: %d\n", num, power, result);
	return result;
}

int tetration(int base, int exponent) {
	int true_exponent = 1;

	for (int i = 1; i < exponent; i++) {
		true_exponent *= base;
	}
	return power( base, true_exponent );
	// This function returns base 
}