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

int remove_head () {
	if (!head) {
		printf("Can't remove the head, since head is NULL\n");
		return 1;
	}

	if (!head->next) {
		free(head);
		head = NULL;
	} else {
		Node *next_node = head->next;
		free(head);
		head = next_node;
	}
	printf("Removed head\n");
	return 0;
}

int remove_tail() {
	if (!head) {
		printf("Can't remove the tail, since head is NULL\n");
		return 1;
	}

	if (!head->next) {
		free(head);
		head = NULL;
	} else {
		Node *current_node = head;

		while (current_node->next->next) {
			current_node = current_node->next;
		}
		
		free(current_node->next);
		current_node->next = NULL;

	}
	printf("Removed tail\n");
	return 0;
}

int get_size() {
	if (!head) {
		return 0;
	}
	int i = 0;
	Node *current_node = head;

	while (current_node != NULL) {
		i ++;
		current_node = current_node->next;
	}
	return i;
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
