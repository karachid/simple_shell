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

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size:is the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 * Return: pointer allocate new size memory or NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i, n = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
		n = old_size;
	for (i = 0; i < n; i++)
		p[i] = oldp[i];
	free(ptr);
	return (p);
}
