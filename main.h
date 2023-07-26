#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **split(char *string, const char *delim);
int count_tok(char *string, const char *delim);
void interactive_shell(char **argv);
void non_interactive_shell(char **argv);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name);
int path_handler(char **tokens);
char *_strcat(char *dest, char *src);
int path_finder(char *command);
void execute_cmd(char **argv, char **token, char *line, char *prompt);
int  cmd_check(char *command);
void exit_handler(int sig_num);
void exit_shell(void);
void env_shell(char *prompt);

#endif
