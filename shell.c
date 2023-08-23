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
 * shell_loop - main loop of the shell
 * @head: head of the path list
 * @pflag: prompt flag
 * @av: prog name
 */
void shell_loop(pathnode_t *head, int pflag, char *av)
{
	char *r = NULL;
	ssize_t n_char = 0;
	size_t len = 0;
	int flag = 0, count = 0;

	while (TRUE)
	{
		flag = 0;
		if (pflag)
			displayprompt();
		n_char = getline(&r, &len, stdin);
		count++;
		if (n_char == 1 && r[0] == '\n')
			continue;
		if (n_char >= 0)
		{
			if (handler(&r, head, &flag, av, n_char, count, pflag))
				continue;
		}
		else
		{
			free(r);
			break;
		}
	}
}
