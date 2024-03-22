#ifndef NODE_H
#define NODE_H

typedef enum {
	INT,
	FLOAT,
	CHAR,
	STRING
} Type;

typedef struct Node {
	Type type;
	union {
		int int_value;
		float float_value;
		char char_value;
		char *string_value;
	} data;
	struct Node *next;
} Node;

#endif
