#include <stdio.h>

struct Node {
	int value;
	struct Node* next_node;
};

int main() {
	struct Node node1 = { 50, NULL};
	struct Node node2 = { 25, NULL};
	node1 = (struct Node){ 10, &node2 };
	return 0;
}
