#ifndef SHELL_H
#define SHELL_H

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
