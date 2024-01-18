#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

char *regexify (char *ip);
char *get_user_input();

int main() {
	// regexify("192.168.0.1");
	// regexify("192.168.168.112");
	while (1) {
		regexify(get_user_input());
	}
}

#define MAX_BUFFER_SIZE 16

char *get_user_input() {
	char *ip_address = malloc(sizeof(char) * MAX_BUFFER_SIZE);

	// Ask user to input the pattern to be checked
	printf("Please input the ip address pattern to be checked: ");

	// Get and save the text
	fgets(ip_address, MAX_BUFFER_SIZE, stdin);

	// remove the newline that fgets appends
	size_t len = strlen(ip_address);

	if (len > 0 && ip_address[len - 1] == '\n') {
		ip_address[len-1] = '\0';
	}

	// return the text
	return ip_address;
}

char *regexify (char *ip) {
	regex_t regex;
	int reti;
	char msgbuf[100];

	size_t max_groups = 5;
	regmatch_t groups[max_groups];

	// pattern for ip address
	char *pattern = "^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$";
	// Compile regular expression
	reti = regcomp(&regex, pattern, REG_EXTENDED);
	if (reti){
		fprintf(stderr, "The pattern cannot be compiled.\n");
		exit(1);
	}

	// Execute regular expression
	reti = regexec(&regex, ip, max_groups, groups, 0);
	if (!reti) {
		puts("Match!");
		for (unsigned int g = 0; g < max_groups; g++) {
			if (groups[g].rm_so == (size_t) - 1)
				break;
			
			char ip_copy[strlen(ip) + 1];
			strcpy(ip_copy, ip);
			ip_copy[groups[g].rm_eo] = 0;
			printf("Group %u: [%2llu-%2llu]: %s\n", g, groups[g].rm_so, groups[g].rm_eo, ip_copy + groups[g].rm_so);
		}
	}
	else if(reti == REG_NOMATCH) {
		puts("No match!");
	}
	else {
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		fprintf(stderr, "Regex match failed, %s\n", msgbuf);
		exit(1);
	}
	// Free compiled regex
	regfree(&regex);
	free(ip);
	return 0;
}
