#include "main.h"

/**
 * cmd_check - Checks if a command is valid or not.
 *
 * @command: Pointer to Character value, which represents the command.
 *
 * Return: 0 (VALID)
 *	   -1 (NOT VALID).
 */
int cmd_check(char *command)
{
	struct stat buff;

	/**
	 * Checking if the given command is NULL or NOT.
	 */
	if (command == NULL)
		return (-1);

	/**
	 * Checking if the given command was a directory or NOT.
	 */
	if (command[0] == '/')
	{
		/**
		 * if the directory was found, it returns 0.
		 * if the directory wasn't found, it returns -1.
		 */
		return (stat(command, &buff));
	}

	else
	{
		/**
		 * The command is not a directory ...
		 * if the command was found, it returns 0.
		 * if the command wasn't found, it returns -1.
		 */
		return (path_finder(command));
	}
}
