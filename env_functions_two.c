#include "shell.h"

/**
 * isenvcommand - Checks whether a command in anv command
 * @cmd: Command input
 * Return: (int) 1 if SUCCESS, 0 otherwise
 */
int isenvcommand(char *cmd)
{
	char *choice[] = {"setenv", "unsetenv", "env", NULL};
	int i;

	for (i = 0; choice[i]; i++)
	{
		if (strcompare(cmd, choice[i], 0))
			return (1);
	}
	return (0);
}

/**
 * handleenvcommand - Handles the env command
 * @tokens: Arrays of string that holds the entire command
 * Return: (void) NOTHING
 */
void handleenvcommand(char **tokens)
{
	if (strcompare(tokens[0], "env", 0) && tokens[1] == NULL)
		printenv();
	else if (strcompare(tokens[0], "setenv", 0) && tokens[1] && tokens[2])
		setenv(tokens[1], tokens[2], 1);
	else if (strcompare(tokens[0], "unsetenv", 0) && tokens[1])
		unsetenvvar(tokens);
}
