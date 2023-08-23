#include "shell.h"

/**
 * printerr - function that print error
 * @progname: programe name
 * @cmd_C: number of command
 * @cmd: name of command
 * @err: error printed
 * Return: (void)
 */

void printerr(char *progname, char *cmd_C, char *cmd, char *err)
{
	write(STDERR_FILENO, progname, strlength(prgm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_C, strlength(cmd_C));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlength(cmd));
	write(STDERR_FILENO, err, strlength(err));
	write(STDERR_FILENO, "\n", 1);
}
