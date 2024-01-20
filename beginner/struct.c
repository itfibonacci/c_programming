#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person {
	int age;
	char name[];
};

int main() {
	struct Person* hakob = malloc(sizeof(struct Person) + sizeof("Hakob Tumanyan"));
	if (hakob == NULL) {
		fprintf(stderr, "Allocation was not successful.");
	}
	hakob->age = 65;
	strcpy(hakob->name, "Hakob Tumanyan");

	printf("Hakob will be %d in 20 years.", (hakob->age+10));
	free(hakob);
	return 0;
}

