#include <stdio.h>

void pointers(int *x) {
	printf("The address of the variable is: %p", x);
	printf("\nThe value of the variable is: %d", *x);
}

void wrong_swap(int a, int b)
{
	int j = a;
	a = b;
	b = j;
	printf("\nWrong swapping operand 1: %d and operand 2: %d", a, b);
}

void wrong_swap2(int *first, int *second)
{
	int *j = first;
	first = second;
	second = j;
}

void correct_swap(int *first, int *second)
{
	int intermediate = *first;
	*first = *second;
	*second = intermediate;
}

int main()
{
	// int yy = 888;
	// pointers(&yy);

	int x = 21;
	int y = 2;
	printf("\nBefore wrong swap: The value of x: %d, the value of y: %d", x, y);
	wrong_swap(x, y);
	printf("\nAfter wrong swap: The value of x: %d, the value of y: %d", x, y);
	printf("\nBefore wrong2 swap: The value of x: %d, the value of y: %d", x, y);
	correct_swap(&x, &y);
	printf("\nAfter wrong2 swap: The value of x: %d, the value of y: %d", x, y);
	printf("\nBefore correct swap: The value of x: %d, the value of y: %d", x, y);
	correct_swap(&x, &y);
	printf("\nAfter correct swap: The value of x: %d, the value of y: %d", x, y);

}

void print_string()
{
	char mystring[100] = "Hello World!";
	
	int i = 0;

	while (mystring[i] != '\0')
	{
		i += 1;
	}

	printf("The last character in the string is: %c, Address of the null character is: %p\n", mystring[i], &mystring[i]);
	printf("The next character is: %c, And the address of that character is: %p", mystring[i+1], &mystring[i+1]);

	int j = 0;

	while (j != 10000)
	{
		printf("The next character is: %c, And the address of that character is: %p\n", mystring[i+j], &mystring[i+j]);
		j += 1;
	}
}
