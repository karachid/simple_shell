#include "shell.h"

/**
 * executecommand - Executes a a command given as input
 * @pathname: Absolute path of the command file
 * @tokens: Arrays that represents the entire command
 * @progname: Represents the shell's name
 */

void executecommand(char *pathname, char **tokens, char *progname)
{
	pid_t pid;
	int status, exit_status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(pathname, tokens, environ) == -1)
		{
			perror(progname);
			exit(2);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		errno = exit_status;
		/**
		 * if (!pflag)
		 * exit(errno);
		 */
	}
}
