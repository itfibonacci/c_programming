#include <stdio.h>
#include <string.h>

/*  
The strcmp() and strncmp() functions return an integer less than,
equal to, or greater than zero if s1 (or the first n bytes
thereof) is found, respectively, to be less than, to match, or be
greater than s2. 
*/

int my_strcmp1(const char *string1, const char *string2);
int my_strcmp2(const char *string1, const char *string2);
int my_strncmp(const char *s1, const char *s2, size_t n);

int main() {
	printf("Test 1: %d\n", my_strcmp1("abc", "abc")); // Expected output: 0
	printf("Test 2: %d\n", my_strcmp1("abc", "abcd")); // Expected output: -1
	printf("Test 3: %d\n", my_strcmp1("abcd", "abc")); // Expected output: 1
	printf("Test 4: %d\n", my_strcmp1("abc", "bbc")); // Expected output: -1
	printf("Test 5: %d\n", my_strcmp1("bbc", "abc")); // Expected output: 1
	printf("Test 6: %d\n", my_strcmp1("", "")); // Expected output: 0
	printf("Test 7: %d\n", my_strcmp1("abc", "")); // Expected output: 1
	printf("Test 8: %d\n", my_strcmp1("", "abc")); // Expected output: -1

	printf("Test 1: %d\n", my_strcmp2("abc", "abc")); // Expected output: 0
	printf("Test 2: %d\n", my_strcmp2("abc", "abcd")); // Expected output: -1
	printf("Test 3: %d\n", my_strcmp2("abcd", "abc")); // Expected output: 1
	printf("Test 4: %d\n", my_strcmp2("abc", "bbc")); // Expected output: -1
	printf("Test 5: %d\n", my_strcmp2("bbc", "abc")); // Expected output: 1
	printf("Test 6: %d\n", my_strcmp2("", "")); // Expected output: 0
	printf("Test 7: %d\n", my_strcmp2("abc", "")); // Expected output: 1
	printf("Test 8: %d\n", my_strcmp2("", "abc")); // Expected output: -1
	return 0;
}

int my_strcmp1(const char *string1, const char *string2) {
	int ps1 = 0;
	int ps2 = 0;
	int strlen1 = strlen(string1);
	int strlen2 = strlen(string2);

	while (ps1 < strlen1 || ps2 < strlen2) {
		if (ps1 < strlen1 && ps2 < strlen2) {
			if (string1[ps1] > string2[ps2]) {
				return 1;
			}
			else if (string1[ps1] < string2[ps2]) {
				return -1;
			}
			else {
				ps1++;
				ps2++;
			}
		}
		else if (ps1 < strlen1) {
			return 1;
		}
		else {
			return -1;
		}
	}
	return 0;
}

int my_strcmp2(const char *string1, const char *string2) {
	int i = 0;
	
	while (string1[i] || string2[i]) {
		if (string1[i] != string2[i]) {
			return (unsigned char)string1[i] - (unsigned char)string2[i];
		}
		i++;
	}

	return 0;
}

int my_strncmp(const char *s1, const char *s2, size_t n) {
		
}
