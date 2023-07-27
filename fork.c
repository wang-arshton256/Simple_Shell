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
			exit(0);

		else if (token[0][0] != '/')
		{
			if (path_handler(token) == -1)
			{
				printf("In fork.c\n");
				perror(argv[0]);
				exit(127);
			}
			exit(0);
		}
		else if (execve(token[0], token, environ) == -1)
		{
			free(*token);
			free(token);
			free(line);
			perror(argv[0]);
			exit(127);
		}
	}
	else if (id > 0)
	{
		wait(&status);
		if (prompt != NULL)
			write(1, prompt, _strlen(prompt));
	}
}


/**
 * shell_fork - Decides to execute a command or not.
 *
 */

void shell_fork(char **argv, char **token, char *prompt, char *line)
{
	if (*token == NULL)
		write(1, prompt, _strlen(prompt));

	else
	{
		if (strcmp(token[0], "exit") == 0)
		{
			free(*token);
			free(token);
			free(line);
			exit_shell();
		}

		else if (strcmp(token[0], "env") == 0)
			env_shell(prompt);

		else if (cmd_check(token[0]) == 0)
			execute_cmd(argv, token, line, prompt);

		else
		{
			perror(argv[0]);
			write(1, prompt, _strlen(prompt));
		}
	}
}
