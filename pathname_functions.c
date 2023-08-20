#include "shell.h"

char *getpathname(char *cmd, pathnode_t *current, int *flag)
{
	char *path;
	struct stat st;
	unsigned int len;

	if (stat(cmd, &st) == 0)
		return (cmd);

	while (current)
	{
		len = strlen(current->pathvalue) + strlen(cmd) + 2;
		path = malloc(sizeof(char) * len);
		if (!path)
		{
			free(path);
			return (NULL);
		}
		strcpy(path, current->pathvalue);
		strcat(path, "/");
		strcat(path, cmd);
		path[len - 1] = '\0';
		if (stat(path, &st) == 0)
		{
			*flag = 1;
			return (path);
		}
		current = current->nextpath;
		free(path);
		path = NULL;
	}
	return (NULL);
}
