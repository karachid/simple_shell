#include "shell.h"

/**
 * isDelimiter - checks if a char is delimiter
 * @c : the character to be checked
 * @delim : delimiter set
 * Return: (int) 1 if delimiter, 0 otherwise
 */

int isDelimiter(char c, char *delim)
{
	int i;

	if (c == '\0')
		return (1);

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (delim[i] == c)
			return (1);
	}
	return (0);
}

/**
 * stringtotokens - splits a string into words
 * @str : string to be splitted
 * @delim : delimiter set
 * Return: (char **) arrays of words
 */

char **stringtotokens(char *str, char *delim)
{
	int j = 0, i = 0, c = 1;
	char **words = NULL;

	for (; str[j] != '\0'; j++)
	{
		if (isDelimiter(str[j], delim))
		{
			words = realloc(words, sizeof(char *) * c);
			words[c - 1] = malloc(sizeof(char) * (j - i + 1));
			if (!words[c - 1])
			{
				perror("Unable to allocate memory");
			}
			stringncopy(words[c - 1], str + i, j - i); /*Need to write this */
			words[c - 1][j - i] = '\0';
			i = j + 1;
			c++;
		}
	}
	if (str[j] == '\0')
	{
		words = realloc(words, sizeof(char *) * c);
		words[c - 1] = malloc(sizeof(char) * (j - i + 1))
		if (!words[c - 1])
		{
			perror("Unable to allocate memory");
		}
		stringncopy(words[c - 1], str + i, j - i); /*Need to write this func */
		words[c - 1][j - i] = '\0';
		c++;
	}
	words = realloc(words, sizeof(char *) * c);
	words[c - 1] = NULL;

	return (words);
}

/**
 * stringtoken - behaves as strtok of string lib
 * @str : string input to be splitted
 * @delim : set of delimiters
 * Return: (char *) a token based on delimiter
 */

char *stringtoken(char *str, char *delim)
{

	static char *nexttok;
	char *begintoken = NULL;

	if (str != NULL)
		nexttok = str;
	else if (nexttok == NULL)
		return (NULL);

	while (*nexttok != '\0' && isDelimiter(*nexttok, delim))
		nexttok++;

	if (*nexttok == '\0')
	{
		nexttok = NULL;
		return (NULL);
	}

	begintoken = nexttok;

	while (*nexttok != '\0' && !isDelimiter(*nexttok, delim))
		nexttok++;

	if (*nexttok != '\0')
	{
		*nexttok = '\0';
		nexttok++;
	}
	else
		nexttok = NULL;

	return (begintoken);
}
