#include "main.h"

/**
 * _getenv - Gets the given environment variable from the set of
 * environment variables.
 *
 * @name: Pointer to a character value, which represents the
 * name of the enviroment variable to be searched for.
 *
<<<<<<< HEAD
 * Return: Address of the envrionment variable.
 *	   NULL if environment variable not found..
=======
 * Return: Address of the value corresponding to the key envrionment variable.
 *	   NULL if environment variable not found.
>>>>>>> 37fc8966bdb8d84f72206d30dd9ec131e4b2dbf8
 */

char *_getenv(char *name)
{
	int i, var_len = _strlen(name) + 1;
	char *token, *env_var = malloc(sizeof(char) * var_len);

	if (name == NULL)
		return (NULL);

	/**
	 * Typecasting the environment variable.
	 * TODO: allocate memory to env_var instead of typecasting.
	 */
	_strcpy(env_var, name);

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");

		if (_strcmp(token, env_var) == 0)
		{
			token = strtok(NULL, "=");
			return (&environ[i][var_len]);
		}
	}
	return (NULL);
}
