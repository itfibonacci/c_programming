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

void print_linkedlist(LinkedList *ll) {
	Node *current = ll->head;
	
	while (current != NULL) {
		switch (current->type)
			{
				case INT:
					printf("%i", current->data.int_value);
					break;
				case FLOAT:
					printf("%f", current->data.float_value);
					break;
				case CHAR:
					printf("%c", current->data.char_value);
					break;
				case STRING:
					printf("%s", current->data.string_value);
					break;
				default:
					break;
			}
		if (current->next != NULL) {
			printf(" -> ");
		}
		current = current->next;
	}
	printf("\n");
}

/*
adds an element of Node to the tail of the list
if head does not exist the new node will be head
returns 0 if the add operation was successful
*/
unsigned char add_last(LinkedList *linkedlist, Type type, void *value) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	if (new_node == NULL) {
		perror("Allocation of the new node failed.");
		return 1;
	}

	new_node->type = type;
	switch (type)
	{
		case INT:
			new_node->data.int_value = *(int *)value;
			break;
		case FLOAT:
			new_node->data.float_value = *(float *)value;
			break;
		case CHAR:
			new_node->data.char_value = *(char *)value;
			break;
		case STRING:
			new_node->data.string_value = (char *)value;
			break;
		default:
			break;
	}

	new_node->next = NULL;

	if (get_head(linkedlist) == NULL) {
		linkedlist->head = new_node;
		return 0;
	}

	Node *current = linkedlist->head;

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = new_node;
	return 0;
}

/*
Returns and removes the head (first element) of this list.
if head does not exist returns NULL
the caller should be freeing the head node after calling this function
*/
Node *remove_head(LinkedList *linkedlist) {
	if (linkedlist->head == NULL) {
		return NULL;
	}

	Node *old_head = linkedlist->head;
	linkedlist->head = linkedlist->head->next;

	return old_head;
}

/*
adds an element of Node to the head of the list
if head does not exist the new node will be head
returns 0 if the add operation was successful
*/
unsigned char add_first(LinkedList *linkedlist, Type type, void *value) {
	Node *new_node = (Node *) malloc(sizeof(Node));

	if (new_node == NULL) {
		perror("Allocation of the new node failed.");
		return 1;
	}

	new_node->type = type;
	switch (type)
	{
		case INT:
			new_node->data.int_value = *(int *)value;
			break;
		case FLOAT:
			new_node->data.float_value = *(float *)value;
			break;
		case CHAR:
			new_node->data.char_value = *(char *)value;
			break;
		case STRING:
			new_node->data.string_value = (char *)value;
			break;
		default:
			break;
	}

	new_node->next = linkedlist->head;
	linkedlist->head = new_node;
	
	return 0;
}
