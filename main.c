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
		non_interactive_shell(argv);
	}
	else
	{
		interactive_shell(argv);
	}
	return (0);
}
