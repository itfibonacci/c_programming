#include <stdlib.h>
#include <stdio.h>

#define INITIAL_SIZE 5

int *create_stack();
int push(int *stack, int size, int top, int element);

int main() {
	int *my_stack = create_stack();
	push(my_stack, INITIAL_SIZE, 0, 22);
	push(my_stack, INITIAL_SIZE, 1, 33);
	push(my_stack, INITIAL_SIZE, 2, 14);
	push(my_stack, INITIAL_SIZE, 3, 20);
	push(my_stack, INITIAL_SIZE, 4, 21);
	push(my_stack, 2 * INITIAL_SIZE, 5, 22);
	push(my_stack, 2 * INITIAL_SIZE, 6, 23);
	push(my_stack, 2 * INITIAL_SIZE, 7, 24);
	push(my_stack, 2 * INITIAL_SIZE, 8, 25);

}

int *create_stack() {
	int *stack = (int *)malloc(sizeof(int) * INITIAL_SIZE);
	if (stack == NULL) {
		return NULL;
	}
	return stack;
}

int push(int *stack, int size, int top, int element) {
	if (size <= top) {
		stack = (int *) realloc(stack, (2*size) * sizeof(int));
	}
	
	stack[top] = element;
	top++;
	return top;
}
