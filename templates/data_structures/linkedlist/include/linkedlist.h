#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct LinkedList {
	Node *head;
} LinkedList;

LinkedList *linkedlist();
unsigned char free_linked_list(LinkedList **ll);
Node *get_head (LinkedList *linkedlist);
unsigned char add_first(LinkedList *linkedlist, Type type, void *value);
unsigned char add_last(LinkedList *linkedlist, Type type, void *value);
Node *remove(LinkedList *linkedlist);
void print_linkedlist(LinkedList *ll);

#endif
