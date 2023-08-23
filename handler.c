#include "shell.h"

/**
 * handler - command handler
 * @r: cmd line
 * @head: path list
 * @flag: flag
 * @av: name of the program
 * @n_char: size of r
 * @count: number of command
 * Return: (int)
 */

int handler(char **r, pathnode_t *head, int *flag,
	char *av, ssize_t n_char, int count)
{
	char **tokens, *pathname, *cmd_c;

	(*r)[n_char - 1] = '\0';
	if (handle_white_space(r))
		return (1);
	tokens = string_to_tokens(*r);
	free(*r), *r = NULL;
	if (isenvcommand(tokens[0]))
	{
		handleenvcommand(tokens);
		return (1);
	}
	if (strcompare(tokens[0], "exit", 4))
		handleexitcommand(tokens, head);
	pathname = getpathname(tokens[0], head, flag);
	if (!pathname)
	{
		cmd_c = number_to_string(count);
		printerr(av, cmd_c, tokens[0], ": not found");
	}	/*perror(av);*/
	else
		executecommand(pathname, tokens, av);
	freeothers(tokens, *flag, pathname);
	return (0);
}

