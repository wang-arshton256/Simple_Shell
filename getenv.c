#include "main.h"


/**
 * _getenv - Gets the given environment variable from the set of
 * environment variables.
 *
 * @name: Pointer to a constant character value, which represents the
 * name of the enviroment variable to be searched for.
 *
 * Return: Address of the envrionment variable.
 *	   NULL if environment variable not found.
 */

char *_getenv(const char *name)
{
	int i;
	char *token, *env_var;

	env_var = (char *)name;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");

		if (_strcmp(token, env_var) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
	}
	return (NULL);
}
