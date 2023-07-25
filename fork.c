#include "main.h"

/**
 * execute_cmd - Executes a command.
 *
 * @argv: Pointer to an array of pointers to character vlaues, represents
 * the arguments given to the main program.
 * @token: Pointer to an array of pointers to character values, represents
 * the first command from the user input.
 * @line: Pointer to Character value, represents the full line of command
 * that the user enters when prompted.
 * @prompt: Pointer to Character value, represents the message that appears
 * for each prompt in the command line.
 *
 * Return: Nothing.
 */
void execute_cmd(char **argv, char **token, char *line, char *prompt)
{
	int id, status;

	id = fork();
	if (id == 0)
	{
		if (*token == NULL)
			exit(-1);

		else if (token[0][0] != '/')
		{
			if (path_handler(token) == -1)
			{
				printf("In fork.c\n");
				perror(argv[0]);
				exit(-1);
			}
			exit(0);
		}
		else if (execve(token[0], token, environ) == -1)
		{
			free(*token);
			free(token);
			free(line);
			perror(argv[0]);
			exit(-1);
		}
	}
	else if (id > 0)
	{
		wait(&status);
		write(1, prompt, _strlen(prompt));
	}
}
