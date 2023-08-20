#include "shell.h"


/**
 * getenvvar - Gets the value of an env given as input
 * @var: variable name for which the value gets retrieved
 * 
 * Return: (char *) value of the var, NULL otherwise
 */
char *getenvvar(char *var)
{
	unsigned int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, var) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
		i++;
	}
	return (NULL);
}

/*
 * setenvvar - Sets an env variable
 * @
 *
 */
int setenvvar(char *r)
{
	char *variable, *value, *token;

	token = stringtoken(r, " ");
	variable = token;
	token = stringtoken(NULL, " ");
	value = token;
	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

int unsetenvvar(char *r)
{
	char *var, *token, *res;

	token = stringtoken(r, " ");
	var = token;
	token = stringtoken(NULL, " ");
	if (token)
	{
		perror("syntax error");
		return (-1);
	}
	if (unsetenv(var) != 0)
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

void handleenvcommand(char *token)
{
	if (strncmp(token, "env", 3) == 0)
		print_env();
	else if (strncmp(token, "setenv", 6) == 0 && token[6] == ' ')
		setenvvar(&token[7]);
	else if (strncmp(token, "unsetenv", 8) == 0 && token[8] == ' ')
		unsetenvvar(&token[9]);

}
