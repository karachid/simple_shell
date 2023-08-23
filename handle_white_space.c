#include "shell.h"

/**
 * handle_white_space - funtion that handle white space
 * @r: input
 * Return: 1 or 0 othewise
 */

int handle_white_space(char **r)
{
	int i;

	for (i = 0; r[0][i] == ' '  ; i++)
		i++;
	if (r[0][i] == '\0')
	{
		free(*r);
		*r = NULL;
		return (1);
	}
	return (0);
}
