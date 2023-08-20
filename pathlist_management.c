#include "shell.h"

pathnode_t *addpathattheend(pathnode_t **head, const char *pathvalue)
{
	pathnode_t *current, *tmp;

	current = malloc(sizeof(pathnode_t));
	if (!current)
		return (NULL);
	current->pathvalue = strdup(pathvalue);
	current->nextpath = NULL;
	if (!*head)
		*head = current;
	else
	{
		tmp = *head;
		while (tmp->nextpath)
			tmp = tmp->nextpath;
		tmp->nextpath = current;
	}
	return (current);
}

pathnode_t *creat_list(pathnode_t *head, char *value)
{
	char *token;

	token = stringtoken(value, ":");
	while (token)
	{
		addpathattheend(&head, token);
		token = stringtoken(NULL, ":");
	}
	return (head);
}
