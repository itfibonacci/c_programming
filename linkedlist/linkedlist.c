#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

struct Node {
	int value;
	Node *next;
};

// initialize a head that points at NULL first
Node *head = NULL;

Node* add_node_tail (int value) {
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

Node* add_node_head (int value) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (!node) {
		fprintf(stderr, "Memory allocation for a new node failed!");
	}
	node->value = value;

	if (!head) {
		head = node;
		return node;
	}

	node->next = head;
	head = node;
	return node;
}

void print_list() {
	Node *current_node = head;
	int i = 1;
	while (current_node != NULL) {
		printf("Node: %d has value: %d\n", i, current_node->value);
		current_node = current_node->next;
		i++;
	}
}

void free_list() {
	Node *current_node = head;
	Node *next_node = NULL;
	int i = 1;
	while (current_node != NULL) {
		next_node = current_node->next;
		free(current_node);
		printf("Node: %d has been freed!\n", i);
		i++;
		current_node = next_node;
	}	
}
