#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char domainSep = '.';

const char* cmd = "wrap";

const char* flag = "-sq";

void err(char* msg) {
	printf("Error: %s\n", msg);
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		err("No arguments");

		return 1;
	}

	if (argc != 1 + 1) {
		err("Wrong number of arguments");

		return 1;
	}

	const char* url = argv[1];

	unsigned int ln = strlen(url);
	if (ln < 1 + 1 + 1) {
		err("Invalid URL; too short");

		return 1;
	}

	int valid = 0;
	for (int i = 0; i < ln; i++) {
		if (url[i] == domainSep) {
			valid = 1;

			break;
		}
	}

	if (!valid) {
		err("Invalid URL; no domain separator");

		return 1;
	}

	char str[512];
	sprintf(str, "%s $(%s %s %s) %s", cmd, cmd, url, flag, flag);

	system(str);

	return 0;
}
