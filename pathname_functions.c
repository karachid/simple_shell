#include "shell.h"

/**
 * getpathname - Gets the absolute pathname of a command
 * @cmd: Command given as input
 * @head: Head oof the paths list
 * @flag: Helper to know if a memory has been allocated
 * Return: (char *) Absolute pathname if found, NULL otherwise
 */
char *getpathname(char *cmd, pathnode_t *head, int *flag)
{
	char *path = NULL;
	struct stat st;
	unsigned int len;

	if (stat(cmd, &st) == 0)
		return (cmd);

	while (head)
	{
		len = strlength(head->pathvalue) + strlength(cmd) + 2;
		path = malloc(sizeof(char) * len);
		if (!path)
		{
			free(path);
			return (NULL);
		}
		strcopy(path, head->pathvalue);
		path = strconcatenate(path, "/");
		path = strconcatenate(path, cmd);

		if (stat(path, &st) == 0)
		{
			*flag = 1;
			return (path);
		}
		head = head->nextpath;
		free(path);
		path = NULL;
	}
	return (NULL);
}
