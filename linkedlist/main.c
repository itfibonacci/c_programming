#include "linkedlist.h"

int main() {
	add_node_tail(5);
	add_node_tail(12);
	add_node_tail(332);
	add_node_tail(51);
	add_node_head(51);
	print_list();
	free_list();
	return 0;
}
