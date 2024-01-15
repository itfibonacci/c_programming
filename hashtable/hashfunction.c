#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_hash (int key);
int mod_hash (int key, int size);

int main() {
	printf("Dictionary with size %d, key: %d would map to %d\n", 100, 144, mod_hash(144, 100));
	printf("key: %d would map to %d\n", 144, random_hash(144));
	printf("key: %d would map to %d\n", 144, random_hash(144));
	return 0;
}

// below is not a good idea since we won't be able to later retrieve this key
int random_hash (int key) {
	int hash = key;
	hash *= 5;
	hash += 230001;
	//srand(time(NULL));
	hash += rand();
	return hash;
}

int mod_hash (int key, int size) {
	return key % size;
}
