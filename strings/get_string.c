#include <stdio.h>

char *get_user_input ();

int main() {
	printf( "%s", get_user_input() );
}

char *get_user_input () {
	char str[10];
	scanf("%s", &str);
	return &str;
}