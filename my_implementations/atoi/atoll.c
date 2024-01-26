#include <stdio.h>
#include <math.h>
#include <limits.h>

long long atoi(char *str);

int main() {
	char mystring1[] = "011232hello world";
	char mystring2[] = "011231231231223244444444444hello world";
	char mystring3[] = "   999032hello world";
	printf("result: %lld\n", atoi(mystring1));
	printf("result: %lld\n", atoi(mystring2));
	printf("result: %lld\n", atoi(mystring3));
}

long long atoll(char *str) {
	long long result = 0;

	int i = 0;
	while ( str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ) {
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') {
		int digit = str[i] - '0';
		result = 10*result + digit;
		i++;
		if ( result > LLONG_MAX / 10 - digit ) {
			return result;
		}
	}

	return result;
}
