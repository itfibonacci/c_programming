#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct LinkedList {
	Node *head;
} LinkedList;

LinkedList *linkedlist();
unsigned char free_linked_list(LinkedList **ll);
Node *get_head (LinkedList *linkedlist);
unsigned char add(LinkedList *linkedlist, Type type, void *value);
void print_linkedlist(LinkedList *ll);

#endif
