#include "shell.h"

int printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
	return (0);
}

void displayprompt(void)
{
	if (write(1, "$ ", 2) == -1)
	{
		perror("Unable to display the prompt");
		exit(EXIT_FAILURE);
	}
}
