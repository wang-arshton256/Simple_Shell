#include "main.h"

/**
 * interactive_shell - Displays a prompt and wait for the user to type a
 * command.
 *
 * @argv: Pointer to string array, that represents arguments given to the
 * program.
 * @environ: Pointer to string array, that represents the environmental variables
 * in the environment that the program executes within.
 *
 * Return: Nothing.
 */

void interactive_shell(char **argv)
{
	char *token, *line = NULL, *prompt = "#cisfun$ ";
	size_t n;
	int id, status;
	ssize_t bytes_read;

	write(1, prompt, _strlen(prompt));

	while ((bytes_read = getline(&line, &n, stdin)) != -1)
	{
		token = strtok(line, "\"\n");

		id = fork();

		if (id == 0)
		{
			if (token == NULL)
			{
				exit(-1);
			}

			else if (execve(token, argv, environ) == -1)
			{
				free(line);
				perror(argv[0]);
				exit(-1);
			}
		}

		else if (id > 0)
		{
			wait(&status);
			/**
			 * Command appears again after execution.
			 */
			write(1, prompt, _strlen(prompt));
		}
	}
	if (bytes_read == -1)
		write(1, "\n", 1);

	free(line);
}


/**
 * non_interactive_sehll - Gets a setr of commands from the user and executes
 * them when the sell level is at 0.
 *
 * @argv: Pointer to an array of pointers to strings, which represents the
 * arguments given to the program.
 *
 * Return: Nothing.
 */
void non_interactive_shell(char **argv)
{
	char *token, *line = NULL;
	int id, status;
	size_t n;
	ssize_t bytes_read;

	while ((bytes_read = getline(&line, &n, stdin)) != -1)
	{
		token = strtok(line, "\"\n");

		id = fork();
		if (id == 0)
		{
			if (execve(token, argv, environ) == -1)
			{
				free(line);
				perror(argv[0]);
				exit (-1);
			}
		}
		else if (id > 0)
		{
			wait(&status);
			token = strtok(NULL, "\"\n");
		}
	}
	free(line);
}
