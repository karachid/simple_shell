#include "shell.h"

void freelist(list_t *head)
{
	list_t *node, *next_node;

	if (!head)
		return;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
}

void freearray(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);

	free(tokens);
}

void freeothers(char **tokens, int flag, char *pathname)
{
	if (flag)
	{
		free(pathname);
		pathname = NULL;
	}
	freearray(tokens);
}
