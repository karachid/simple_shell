#include "shell.h"

/**
 * printenv - Prints the anv variable
 * Return: void (NOTHING)
 */
void printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlength(environ[i]));
		write(1, "\n", 1);
	}
}

/**
 * displayprompt - Displays the shell's prompt
 * Return: void (NOTHING)
 */
void displayprompt(void)
{
	if (write(1, "$ ", 2) == -1)
	{
		perror("Unable to display the prompt");
		exit(EXIT_FAILURE);
	}
}



/**
 * _atoi - converts a string to an integer
 * @str: input string
 * Return: int (RESULT OF CONVERSION)
 */
int _atoi(char *str)
{
	int sign, i;
	unsigned int res;

	res = i = 0;
	sign = 1;
	while (!(str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
