#include "shell.h"

/**
 * freelist - Frees the allocated memory for the paths list
 * @head: Head of the paths list
 * Return: (void) NOTHING
 */
void freelist(pathnode_t *head)
{
	pathnode_t *node, *next_node;

	if (!head)
		return;
	node = head;
	while (node)
	{
		next_node = node->nextpath;
		free(node->pathvalue);
		free(node);
		node = next_node;
	}
}

/**
 * freearray - Frees the allocated memory of the array command
 * @tokens: Array of the command
 * Return: (void) NOTHING
 */
void freearray(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);

	free(tokens);
}

/**
 * freeothers - Frees any other memory at the end of the prog
 * @tokens: Array of string for the entered command
 * @flag: Flag that helps freeing memory
 * @pathname: Absolute pathname of the command
 * Return: (void) NOTHING
 */
void freeothers(char **tokens, int flag, char *pathname)
{
	if (flag)
	{
		free(pathname);
		pathname = NULL;
	}
	freearray(tokens);
}
