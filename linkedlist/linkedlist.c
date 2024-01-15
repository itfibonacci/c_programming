#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
	int value;
	Node *next;
};

// initialize a head that points at NULL first
Node *head = NULL;

Node* add_node (int value) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (!node) {
		fprintf(stderr, "Memory allocation for a new node failed!");
	}
	node->value = value;

	if (!head) {
		head = node;
		return node;
	}

	Node *current_node = head;

	while (1) {
		if (current_node->next == NULL) {
			current_node->next = node;
			return node;
		}
		current_node = current_node->next;
	}
}
