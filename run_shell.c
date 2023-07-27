#include "main.h"

/**
 * interactive_shell - Displays a prompt and wait for the user to type a
 * command.
 *
 * @argv: Pointer to string array, that represents arguments given to the
 * program.
 *
 * Return: Nothing.
 */

void interactive_shell(char **argv)
{
	char **token = NULL, *line = NULL, *prompt = "#cisfun$ ";
	size_t n;
	ssize_t bytes_read;

	write(1, prompt, _strlen(prompt));

	while ((bytes_read = getline(&line, &n, stdin)) != -1)
	{
		token = split(line, " \"\n");

		shell_fork(argv, token, prompt, line);
	}
	if (bytes_read == -1)
		write(1, "\n", 1);

	if (token != NULL)
	{
		free(*token);
		free(token);
	}
	free(line);
}


/**
 * non_interactive_shell - Gets a set of commands from the user and executes
 * them when the sell level is at 0.
 *
 * @argv: Pointer to an array of pointers to strings, which represents the
 * arguments given to the program.
 *
 * Return: Nothing.
 */
void non_interactive_shell(char **argv)
{
	char **token, *line = NULL;
	size_t n;
	ssize_t bytes_read;

	while ((bytes_read = getline(&line, &n, stdin)) != -1)
	{
		token = split(line, " \"\n");

		if (*token == NULL)
			exit(0);
		else
		{
			if (_strcmp(token[0], "exit") == 0)
				exit_shell();

			else if (_strcmp(token[0], "env") == 0)
				env_shell(NULL);

			else if (cmd_check(token[0]) == 0)
			{
				execute_cmd(argv, token, line, NULL);
			}
			else
			{
				perror(argv[0]);
				exit(127);
			}
		}
	}
	if (token == NULL)
	{
		free(token);
		free(*token);
	}
	free(line);
}
