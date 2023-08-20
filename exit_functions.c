#include "shell.h"

void handleexitcommand(char **tokens, pathnode_t *head)
{
	int num = 0;

	if (tokens[1])
		num = atoi(tokens[1]);
	freelist(head);
	freearray(tokens);
	exit(num);
}
