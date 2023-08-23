#include "shell.h"


char **string_to_tokens(char *r)
{
	int i = 0, k = 0;
	char *token, **args = NULL;

	token = strtok(r, " \t\n");
	while (token)
	{
		i++;
		args = realloc(args, sizeof(char *) * i);
		if (!args)
		{
			perror("realloc");
			if (k > 0)
				while (k--)
					free(args[k]);
			free(args);
		}
		args[k] = malloc(sizeof(char) * (strlength(token) + 1));
		if (!args[k])
		{
			while (k--)
				free(args[k]);
			free(args);
		}
		strcopy(args[k], token);
		k++;
		token = strtok(NULL, " \t\n");
	}
	args[k] = NULL;

	return (args);
}
