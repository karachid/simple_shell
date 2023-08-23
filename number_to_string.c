#include "shell.h"

/**
 * number_to_string - function that convert number to a string
 * @num: number to convert
 * Return: string number
 */

char *number_to_string(int num)
{
	char *str;
	int i = 0, n, prc = 1, j, r;

	n = num;
	while (num)
	{
		num = num / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);

	for (j = 1; j < i; j++)
		prc = prc * 10;
	for (j = 0; j < i; j++)
	{
		r = n / prc;
		if (r <= 9 && r <= 1)
			str[j] = r + 48;
		else
			str[j] = (r % 10) + 48;
		prc = prc / 10;
	}
	str[i] = '\0';
	return (str);
}
