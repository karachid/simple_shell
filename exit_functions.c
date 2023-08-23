#include "shell.h"

/**
 * handleexitcommand - Handles the exit command
 * @tokens: Arrays of the entire command
 * @head: Head of the paths list
 * @count: number of commands typed
 * Return: (void) NOTHING
 */
void handleexitcommand(char **tokens, pathnode_t *head, int count)
{
	int num = 0;

	if (tokens[1])
		num = _atoi(tokens[1]);
	freelist(head);
	freearray(tokens);
	if (tokens[1])
		exit(num);
	exit(count != 1 ? errno : 0);
}
