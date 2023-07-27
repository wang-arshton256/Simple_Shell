#include "main.h"

/**
 * main - Runs the shell.
 *
 * @argc: Integer value, represents the number of arguments given to the
 * program.
 *
 * @argv: Pointer to an array of character values, represents the arguments
 * given to the program.
 *
 * Return: 0 (Success).
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int status = isatty(0);

	if (status != 1)
	{
		non_interactive_shell(argv);
	}
	else
	{
		interactive_shell(argv);
	}
	return (0);
}
