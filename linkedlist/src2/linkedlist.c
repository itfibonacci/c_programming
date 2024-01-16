#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

struct Node {
	int value;
	Node *next;
};

Node *head = NULL;

Node *add_tail(int value) {
	Node *node = (Node *)malloc(sizeof(Node));	
	if (!node) {
		fprintf(stderr, "Allocation failed.\n");
	}
	node->value = value;
	node->next = NULL;

	if (!head) {
		head = node;
		return node;
	}

	Node *current_node = head;
	while (current_node->next != NULL) {
		current_node = current_node->next;
	}
	current_node->next = node;
	return node;
}

void print_list() {
	Node *current_node = head;
	int i = 1;
	while (current_node != NULL) {
		printf("Node: %d has value - %d\n", i, current_node->value);
		current_node = current_node->next;
		i++;
	}
}

size_t get_size() {
	int i = 0;
	Node *current_node = head;
	while(current_node != NULL) {
		current_node = current_node->next;
		i++;
	}
	return i;
}

void free_list() {
	Node *current_node = head;
	int i = 0;
	while (current_node != NULL) {
		Node *next_node = current_node->next;
		free(current_node);
		current_node = next_node;
		i++;
	}
	printf("%d nodes have been freed.\n", i);
}

void reverse_list_bad() {
	// add freeing of memory if necessary
	printf("Reversing the list.\n");
	int items[get_size()];
	Node *current_node = head;
	int i = 0;
	while (current_node != NULL) {
		items[i] = current_node->value;
		current_node = current_node->next;
		i++;
	}
	i = get_size() - 1;
	free_list();
	head = NULL;
	while (i > -1) {
		add_tail(items[i]);
		i--;
	}
}

void reverse_list_good() {
	printf("Good reverse.\n");
	Node *node_addresses[get_size()];

	int i = 0;
	Node *current_node = head;

	while (current_node != NULL) {
		node_addresses[i] = current_node;
		current_node = current_node->next;
		i++;
	}

	i = get_size() - 1;
	head = node_addresses[i];
	current_node = head;
	while (i > 0) {
		current_node->next = node_addresses[i - 1];
		i--;
		current_node = node_addresses[i];
	}
	current_node->next = NULL;
}
