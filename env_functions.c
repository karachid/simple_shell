#include "shell.h"

/**
 * getenvvar - Retrives the value of an env var given as input
 * @name: Name of the variable
 * Return: (char *) which represents the value, NULL otherwise
 */
char *getenvvar(char *name)
{
	int i = 0;
	char *envvar;
	size_t namesize;

	if (name == NULL || name[0] == '\0')
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		envvar = environ[i];
		namesize = strlen(name);
		if (strncmp(envvar, name, namesize) == 0 && envvar[namesize] == '=')
			return (envvar + namesize + 1);
	}
	return (NULL);
}


/**
 * setenvvar - Sets the value of an env variable
 * @tokens: Arrays of string that holds the entire command
 * Return: (int) 0 if SUCCESS, -1 otherwise
 */
int setenvvar(char **tokens)
{
	if (setenv(tokens[1], tokens[2], 1) != 0)
	{
		perror("Unable to set the env variable");
		return (-1);
	}
	return (0);
}


/**
 * unsetenvvar - Unsets the value of an env variable
 * @tokens: Arrays of string that holds the entire command
 * Return: (int) 0 if SUCCESS, -1 otherwise
 */
int unsetenvvar(char **tokens)
{
	if (unsetenv(tokens[1]) != 0)
	{
		perror("setenv");
		exit(-1);
	}
	return (0);
}

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
		if (strcmp(cmd, choice[i]) == 0)
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
	if (strcmp(tokens[0], "env") == 0 && tokens[1] == NULL)
		printenv();
	else if (strcmp(tokens[0], "setenv") == 0 && tokens[1] && tokens[2])
		setenvvar(tokens);
	else if (strcmp(tokens[0], "unsetenv") == 0 && tokens[1])
		unsetenvvar(tokens);
}
