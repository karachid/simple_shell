#include "shell.h"

/**
 * main - Entry point of the shell
 * Decription: Main functions that serves as an entry point
 * @ac: Number of arguments
 * @av: Array of arguments
 * Return: Always 0 (SUCCESS)
 */

int main(int ac, char **av)
{
	char *pathname, *value, *r = NULL, **tokens;
	ssize_t n_char;
	size_t len = 0;
	int flag;
	pathnode_t *head = NULL;
	(void)ac;

	value = _getenv("PATH");
	head = creat_list(head, value);
	while (1)
	{
		flag = 0;
		displayprompt();
		n_char = getline(&r, &len, stdin);
		if (n_char >= 0)
		{
			r[n_char - 1] = '\0';
			tokens = stringtotokens(r, " ");
			free(r);
			r = NULL;
			if (isenvcommand(tokens[0]))
			{
				handleenvcommand(tokens);
				continue;
			}
			if (strcmp(tokens[0], "exit") == 0)
				handleexitcommand(tokens, head);
			pathname = getpathname(tokens[0], head, &flag);
			if (!pathname)
				printf("--command not found\n");
			else
				executecommand(pathname, tokens, av[0]);
			freeothers(tokens, flag, pathname);
		}
		else
			break;
	}
	freelist(head);
	return (0);
}
