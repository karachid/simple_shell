#include "shell.h"

/**
 * strlength - returns the length of a given string
 * @str: string pointer
 * Return: uint (size of the string)
 */
unsigned int strlength(char *str)
{
	unsigned int s = 0;

	if (!str)
		return (0);

	while (str[s] != '\0')
	{
		s++;
	}
	return (s);
}

/**
 * strduplicate - duplicates an string
 * @str: string input to be duplicated
 * Return: char* (pointer to the duplicated string)
 */
char *strduplicate(char *str)
{
	char *newstr = NULL;
	int len, idx;

	if (!str)
		return (NULL);

	len = strlength(str) + 1;

	newstr = malloc(sizeof(char) * len);

	if (!newstr)
	{
		perror("Unable to allocate memory");
		return (NULL);
	}
	for (idx = 0; idx < len ; idx++)
	{
		newstr[idx] = str[idx];
	}

	return (newstr);
}

/**
 * strcompare - compares two given strings
 * @strf: first input
 * @strs: second input
 * @n: number of characters to be compared, 0 if infinite
 * Return: int (1 if both are same,0 otherwise)
 */
int strcompare(char *strf, char *strs, int n)
{
	int i;

	if (strf == NULL && strs == NULL)
		return (1);

	if (strf == NULL || strs == NULL)
		return (0);

	if (n == 0)
	{
		if (strlength(strf) != strlength(strs))
			return (0);
		for (i = 0; strf[i]; i++)
		{
			if (strf[i] != strs[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < n ; i++)
		{
			if (strf[i] != strs[i])
				return (0);
		}
		return (1);
	}
}

/**
 * strconcatenate - concatenates two strings
 * @dest: first argument
 * @src: second argument
 * Return: concatenated string
 */

char *strconcatenate(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * strcopy - copies src into dest
 * @dest: destination string
 * @src: source string
 * Return: array of char
 */
char *strcopy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
