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

	namesize = strlength(name);

	for (i = 0; environ[i]; i++)
	{
		envvar = environ[i];
		if (strcompare(envvar, name, namesize) && envvar[namesize] == '=')
			return (envvar + namesize + 1);
	}
	return (NULL);
}

/**
 * containschar - checks whether a string contains a char or not
 * @str: string input
 * @c: character to look for in the string input
 * Return: int
 */

int containschar(char *str, char c)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

/**
 * setenvvar - Sets the value of an env variable
 * @name: name of the variable
 * @value: value to be set
 * @overwrite: allows to know whether to overwite the value or not
 * Return: (int) 0 if SUCCESS, -1 otherwise
 */
int setenvvar(char *name, char *value, int overwrite)
{
	size_t size;
	char *newvar;

	if (name == NULL || name[0] == '\0' || containschar(name, '='))
		return (-1);

	if (!overwrite)
	{
		if (getenv(name) != NULL)
			return (0);
	}

	size = strlength(name) + strlength(value) + 2;
	newvar = (char *) malloc(size);

	if (newvar == NULL)
	{
		return (-1);
	}

	snprintf(newvar, size, "%s=%s", name, value);

        if (putenv(newvar) != 0)
	{
		free(newvar);
		return (-1);
	}
	free(newvar);
	return (0);
}

/**
 * putenvvar - puts a new env variable
 * @name: name of the variable
 * @value: value to be set
 * Return: int
 */
int putenvvar(char *name, char *value)
{
	int i = 0, j = 0;
	char *s, **newenviron = NULL;

	printf("%s | %s\n", name, value);

	for (; environ[i]; i++)
	{
		if (strcompare(name, environ[i], strlength(name))
		    && environ[i][strlength(name)] == '=')
		{
			s = malloc(sizeof(char) * (strlength(name) + strlength(value) + 2));
			s = strconcatenate(s, name);
			s = strconcatenate(s, "=");
			s = strconcatenate(s, value);
			environ[i] = s;
			return (0);
		}
	}

	newenviron = (char **) realloc(newenviron, sizeof(char *) * (i + 1));
	if (newenviron == NULL)
		printf("its NULL\n");
	while (environ[j])
	{
		newenviron[j] = environ[j];
		j++;
	}
	newenviron[i] = malloc(sizeof(char) * (strlength(name) + strlength(value) + 2));
	newenviron[i] = strconcatenate(newenviron[i], name);
	newenviron[i] = strconcatenate(newenviron[i], "=");
	newenviron[i] = strconcatenate(newenviron[i], value);
	newenviron[i + 1] = NULL;
	environ = newenviron;
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

	if (getenv(tokens[1]))
		printf("%s\n", getenv(tokens[1]));
	else
		printf("%s\n", "(NIL)");

	return (0);
}
