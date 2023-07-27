#include "main.h"

/**
 * path_handler - Searches for the right path of the first command given by
 * the user in prompt and executes it (with respect to arguments provided if
 * any) once the command is  found.
 *
 * @tokens: Pointer to an array of pointers to character values, which
 * represents the set of arguments beside the command.
 *
 * Return: 0 (Success)
 *	   -1 (FAILURE).
 */
int path_handler(char **tokens)
{
	char *directory, *path_value = _getenv("PATH");
	char **paths;
	int cmd_len, dir_len, i = 0;
	struct stat buff;

	path_value = strtok(path_value, "=");
	paths = split(path_value, ":");
	cmd_len = _strlen(tokens[0]) + 2;

	while (paths[i] != NULL)
	{

		/**
		 * Single directory separated by ':' in the same order of
		 * $PATH
		 */
		dir_len = _strlen(paths[i]) + cmd_len;
		directory = malloc(sizeof(char) * dir_len);

		_strcpy(directory, paths[i]);
		directory = _strcat(directory, "/");
		directory = _strcat(directory, tokens[0]);

		if (stat(directory, &buff) == 0)
		{
			execve(directory, tokens, environ);
			free(directory);
			return (0);
		}
		free(directory);
		i++;
	}
	return (-1);
}

/**
 * path_finder - Tells you if the command is valid or not.
 *
 * @command: Pointer to Character value, represents the name of the command.
 *
 * Return: 0 (FOUND)
 *	   1 (NOT FOUND)
 */
int path_finder(char *command)
{
	char *directory, *path_value = _getenv("PATH");
	char **paths;
	int cmd_len, dir_len, i = 0;
	struct stat buff;

	path_value = strtok(path_value, "=");
	paths = split(path_value, ":");
	cmd_len = _strlen(command) + 2;

	while (paths[i] != NULL)
	{

		/**
		 * Single directory separated by ':' in the same order of
		 * $PATH
		 */
		dir_len = _strlen(paths[i]) + cmd_len;
		directory = malloc(sizeof(char) * dir_len);

		_strcpy(directory, paths[i]);
		directory = _strcat(directory, "/");
		directory = _strcat(directory, command);

		if (stat(directory, &buff) == 0)
		{
			return (0);
		}
		i++;
	}
	return (-1);
}
