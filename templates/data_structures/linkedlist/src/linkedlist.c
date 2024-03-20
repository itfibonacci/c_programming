#include <stdio.h>
#include <stdlib.h>

typedef enum {
	INT,
	CHAR,
	STRING
} Type;

typedef struct Node {
	Type type;
	void *data;
	struct Node *next;
} Node;

typedef struct LinkedList {
	Node *head;
} LinkedList;

LinkedList *linkedlist();
Node *get_head (LinkedList *linkedlist);
unsigned char add(LinkedList *linkedlist, Type type, void *value);

int main() {
	LinkedList *ll1 = linkedlist();
	printf("The first ll's head is at: %p\n", ll1->head);
	printf("The first ll's head is at: %p\n", get_head(ll1));
	add(ll1, INT, 123);
	printf("The first node's data is: %d", get_head(ll1)->data);
}

LinkedList *linkedlist() {
	LinkedList *new_linked_list = (LinkedList *) malloc(sizeof(LinkedList));
	
	if (new_linked_list == NULL) {
		perror("Allocation of the new node failed.");
		return NULL;
	}
	
	new_linked_list->head = NULL;
	return new_linked_list;
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
