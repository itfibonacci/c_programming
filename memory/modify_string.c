#include <stdio.h>

void modify_string(char **name);

int main() {
	char *name = "Brianna";
	char **ptr = &name;
	printf("Name was: %s\n", name);
	modify_string(ptr);
	printf("Name is: %s\n", name);
	return 0;
}

void modify_string(char **name) {
	*name = "Blackiana";
}