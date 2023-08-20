#include "shell.h"


/**
 * addpathattheend - Adds a path node at the end of the paths list
 * @head: pointer to the head of the paths list
 * @pathvalue: Value of the new path to add to the paths list
 * Return: (pathnode_t) Address of the new allocated path node
 */
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

/**
 * createlist - Creates a list from the PATH env variable
 * @head: Pointer to the header of the paths list
 * @value: The value of PATH to be used for creating the paths list
 * Return: (pathnode_t) Head of the paths list
 */
pathnode_t *createlist(pathnode_t *head, char *value)
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
