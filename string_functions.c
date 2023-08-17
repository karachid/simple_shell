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
		for (i = 0; i < number ; i++)
		{
			if (strf[i] != strs[i])
			return (0);
		}
		return (1);
	}
}

/**
 * strconcatenate - concatenates two given strings
 * @strf: first input string
 * @strs: seconf input string
 * Return: (char*) pointer to the new string
 */
char *strconcatenate(char *strf, char *strs)
{
	char *newstr = NULL;
	int lenf = 0, lens = 0;

	if (strf == NULL)
		strf = "";
	lenf = strlength(strf);

	if (strs == NULL)
		strs = "";
	lens = strlength(strs);

	newstr = malloc(sizeof(char) * (lenf + lens + 1));
	if (!newstr)
	{
		perror("Unable to allocate memory");
		return (NULL);
	}

	for (lenf = 0; strf[lenf] != '\0'; lenf++)
		newstr[lenf] = strf[lenf];
	free(strf);

	for (lens = 0; strs[lens] != '\0'; lens++)
	{
		newstr[lenf] = strs[lens];
		lenf++;
	}

	newstr[lenf] = '\0';
	return (newstr);
}

/**
 * stringncopy - copies n char from src to dest
 * @dest : destination string
 * @src : source string
 * @n : amount of char to be copied
 * Return: (char *) pointer to the new string
 */

char *stringncopy(char *dest, const char *src, size_t n)
{

	char *dests = dest;

	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}

	return (dests);
}
