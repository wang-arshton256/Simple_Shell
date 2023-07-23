#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

extern char **environ;

char **split(char *string, const char *delim);
int count_tok(char *string, const char *delim);
void interactive_shell(char **argv);
void non_interactive_shell(char **argv);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);

#endif
