#include "main.h"

/**
 * main - Tests the shell.
 *
 * @argc: Integer value, represents the number of arguments given to the
 * program.
 * @argv: Pointer to an array of character values, represents the arguments
 * given to the program.
 *
 * Return: 0 (Success).
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *shell_filter = "SHLVL";
	char *shell_lvl = _getenv(shell_filter);

	if (_strcmp(shell_lvl, "0") == 0)
	{
		/**
		if (getline(&line, &n, stdin) != -1)
		{
			token = strtok(line, "\"\n");

			while (token != NULL)
			{
				id = fork();
				if (id == 0)
				{
					if (execve(token, argv, environ) == -1)
					{
						perror(argv[0]);
						return (-1);
					}
				}
				else if (id > 0)
				{
					wait(&status);
					token = strtok(NULL, "\"\n");
				}
			}
		}
		*/
		non_interactive_shell(argv);
	}
	else
	{
		interactive_shell(argv);
	}
	return (0);
}
