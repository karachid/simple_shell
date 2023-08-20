#include "shell.h"

void executecommand(char *pathname, char **tokens, char *progname)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(pathname, tokens, NULL) == -1)
		{
			perror(progname);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
