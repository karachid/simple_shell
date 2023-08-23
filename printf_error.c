#include "shell.h"


void printerr(char *prgm, char *cmd_C, char *cmd, char *err)
{
	write(STDERR_FILENO, prgm, strlength(prgm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_C, strlength(cmd_C));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlength(cmd));
	write(STDERR_FILENO, err, strlength(err));
	write(STDERR_FILENO, "\n", 1);
}
