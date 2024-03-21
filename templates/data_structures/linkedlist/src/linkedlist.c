#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

LinkedList *linkedlist() {
	LinkedList *new_linked_list = (LinkedList *) malloc(sizeof(LinkedList));
	
	if (new_linked_list == NULL) {
		perror("Allocation of the new node failed.");
		return NULL;
	}
	
	new_linked_list->head = NULL;
	return new_linked_list;
}

/* 
Returns 0 if the method successfully has freed memory
*/
unsigned char free_linked_list(LinkedList **ll) {
	// let's go one by one and free all the nodes
	Node *current = (*ll)->head;
	Node *next;
	
	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	free(*ll);
	*ll = NULL;
	return 0;
}

/* returns null if the collection is empty */
Node *get_head (LinkedList *linkedlist) {
	return linkedlist->head;
}

/*
adds an element of Node to the head of the list
if head does not exist the new node will be head
returns 0 if the add operation was successful
*/
unsigned char add(LinkedList *linkedlist, Type type, void *value) {
	Node *new_node = (Node *) malloc(sizeof(Node));

	if (new_node == NULL) {
		perror("Allocation of the new node failed.");
		return 1;
	}

	new_node->type = type;
	new_node->data = value;
	new_node->next = linkedlist->head;
	linkedlist->head = new_node;
	
	return 0;
}
