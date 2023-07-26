#include "main.h"

/**
 * env_shell - Prints all the envrionment variables of a shell.
 *
 * @prompt: Pointer to Character value, represents the message prompt.
 *
 * Return: Nothing.
 */

void env_shell(char *prompt)
{
	int i = 0;
	char *env_var;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = _getenv(environ[i]);
		if (env_var == NULL)
			env_var = "";
		write(1, environ[i], _strlen(environ[i]));
		write(1, "=", 1);
		write(1, env_var, _strlen(env_var));
		write(1, "\n", 1);
	}
	write(1, prompt, _strlen(prompt));
}
