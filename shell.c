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
	char *value = getenvvar("PATH");
	int pflag = 0;
	pathnode_t *head = NULL;
	(void)ac;

	head = createlist(head, value);

	if (isatty(STDIN_FILENO))
		pflag = 1;

	shell_loop(head, pflag, av[0]);

	freelist(head);
	return (0);
}

/**
 * shell_loop - main llop of the shell
 * @head: head of the path list
 * @pflag: prompt flag
 * @av: prog name
 */
void shell_loop(pathnode_t *head, int pflag, char *av)
{
	char *pathname, *r = NULL, **tokens;
	ssize_t n_char = 0;
	size_t len = 0;
	int flag = 0, i;

	while (TRUE)
	{
		flag = 0;
		if (pflag)
			displayprompt();
		n_char = getline(&r, &len, stdin);
		if (n_char == 1 && r[0] == '\n')
			continue;
		if (n_char >= 0)
		{
			r[n_char - 1] = '\0';
			if (handle_white_space(&r))
				continue;
			tokens = string_to_tokens(r);
			printf("r : %s -- len : %ld\n", r, strlen(r));
			for (i = 0; tokens[i]; i++)
				printf("r : %s -- len : %ld\n", tokens[i], strlen(tokens[i]));
			free(r);
			r = NULL;
			if (isenvcommand(tokens[0]))
			{
				handleenvcommand(tokens);
				continue;
			}
			if (strcompare(tokens[0], "exit", 4))
				handleexitcommand(tokens, head);
			pathname = getpathname(tokens[0], head, &flag);
			if (!pathname)
				perror(av);
			else
				executecommand(pathname, tokens, av);
			freeothers(tokens, flag, pathname);
		}
		else
			break;
	}
}
