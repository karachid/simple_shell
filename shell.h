#ifndef SHELL_H
#define SHELL_H

/* Returns the length of a given string */
int str_length(char *string);

/* Returns a duplicated string similar to a given input */
char *str_duplicate(char *string);

/* Allows to compare two strings given as inputs */
int str_compare(char *string1, char *string2, int number);

/* Returns the concatenation of two strings given as inputs */
char *str_concat(char *string1, char *string2);

#endif
