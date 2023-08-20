#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1

extern char **environ;


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


/* Pathlist functions */
pathnode_t *addpathattheend(pathnode_t **head, const char *pathvalue);
pathnode_t *createlist(pathnode_t *head, char *value);

/* Helper functions */
void printenv(void);
void displayprompt(void);

/* Exit handler functions */
void handleexitcommand(char **tokens, pathnode_t *head);

/* Execute functions */
void executecommand(char *pathname, char **tokens, char *progname);

/* Memory management functions */
void freelist(pathnode_t *head);
void freearray(char **tokens);
void freeothers(char **tokens, int flag, char *pathname);

/* Pathname management functions */
char *getpathname(char *cmd, pathnode_t *head, int *flag);

/* Functions for managing envirnment variables */
char *getenvvar(char *name);
int setenvvar(char **tokens);
int unsetenvvar(char **tokens);
int isenvcommand(char *cmd);
void handleenvcommand(char **tokens);


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
char *str_concatenate(char *strf, char *strs);

/* Copies n characters from sources to destination */
char *stringncopy(char *dest, const char *src, size_t n);

#endif
