#include "shell.h"

/**
 * printenv - Prints the anv variable
 * Return: void (NOTHING)
 */
void printenv(void)
{
	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}

/**
 * displayprompt - Displays the shell's prompt
 * Return: void (NOTHING)
 */
void displayprompt(void)
{
	if (write(1, "$ ", 2) == -1)
	{
		perror("Unable to display the prompt");
		exit(EXIT_FAILURE);
	}
}
