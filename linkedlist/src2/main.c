#include <stdio.h>
#include "linkedlist.h"

int main() {
	add_tail(123);
	add_tail(2);
	add_tail(23);
	print_list();
	add_tail(-12);
	add_tail(134);
	add_tail(21);
	print_list();
	reverse_list_bad();
	print_list();
	reverse_list_good();
	print_list();
	printf("Size of the list is: %zu\n", get_size());
	free_list();
	return 0;
}
