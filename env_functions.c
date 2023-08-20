#include "shell.h"


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

int setenvvar(char **tokens)
{
	if (setenv(tokens[1], tokens[2], 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

int unsetenvvar(char **tokens)
{
	if (unsetenv(tokens[1]) != 0)
	{
		perror("setenv");
		exit(EXIT_FAILURE);
	}
	return (0);
}

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

void handleenvcommand(char **tokens)
{
	if (strcmp(tokens[0], "env") == 0 && tokens[1] == NULL)
		print_env();
	else if (strcmp(tokens[0], "setenv") == 0 && tokens[1] && tokens[2])
		_setenv(tokens);
	else if (strcmp(tokens[0], "unsetenv") == 0 && tokens[1])
		_unsetenv(tokens);
}
