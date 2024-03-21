#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
unsigned char free_linked_list(LinkedList **ll);
Node *get_head (LinkedList *linkedlist);
unsigned char add(LinkedList *linkedlist, Type type, void *value);

#endif
