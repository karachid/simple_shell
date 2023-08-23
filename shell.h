#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define TRUE 1

/**
 * struct pathnode - pathnode structure
 * @pathvalue: holds a path value
 * @nextpath: points to the next path in the list
 */

typedef struct pathnode
{
	char *pathvalue;
	struct pathnode *nextpath;
} pathnode_t;

/* new addition */
char **string_to_tokens(char *r);
int handle_white_space(char **r);
int handler(char **r, pathnode_t *head, int *flag, char *av, ssize_t n_char, int count);
void printerr(char *prgm, char *cmd_C, char *cmd, char *err);
char *number_to_string(int num);
/*************/


extern char **environ;


/* Main function */
void shell_loop(pathnode_t *head, int pflag, char *av);

/* Pathlist functions */
pathnode_t *addpathattheend(pathnode_t **head, char *pathvalue);
pathnode_t *createlist(pathnode_t *head, char *value);

/* Helper functions */
void printenv(void);
void displayprompt(void);
int _atoi(char *str);

/* Exit handler functions */
void handleexitcommand(char **tokens, pathnode_t *head);

/* Execute functions */
void executecommand(char *pathname, char **tokens, char *progname);

/* Memory management functions */
void freelist(pathnode_t *head);
void freearray(char **tokens);
void freeothers(char **tokens, int flag, char *pathname);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* Pathname management functions */
char *getpathname(char *cmd, pathnode_t *head, int *flag);

/* Functions for managing envirnment variables */
char *getenvvar(char *name);
int setenvvar(char *name, char *value, int overwrite);
int unsetenvvar(char **tokens);
int isenvcommand(char *cmd);
void handleenvcommand(char **tokens);
int containschar(char *str, char c);
int putenvvar(char *name, char *value);

/* Checks whether a given character is a delimiter or not */
int isDelimiter(char c, char *delim);

/* Split a string into words based on a set of delimiters */
char **stringtotokens(char *str, char *delim);

/* Behaves as strtok of C string library */
char *stringtoken(char *str, char *delim);

/* Returns the length of a given string */
unsigned int strlength(char *str);

/* Returns a duplicated string similar to a given input */
char *strduplicate(char *str);

/* Allows to compare two strings given as inputs */
int strcompare(char *strf, char *strs, int n);

/* Returns the concatenation of two strings given as inputs */
char *strconcatenate(char *strf, char *strs);

/* Copies source to destination */
char *strcopy(char *dest, char *src);

/* Copies n characters from sources to destination */
char *stringncopy(char *dest, char *src, int n);

#endif
