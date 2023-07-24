#include "main.h"

/**
 * split - Breaks a string into a set of tokens according to the delimiter
 * given and return an array of these tokens.
 *
 * @string: Pointer to Character value, that holds the string to be splitted.
 * @delim: Pointer to a Constant Character value, that holds the delimiter
 * which the string is going to be splitted according to it.
 *
 * Return: Address of the two dimensional array that hold the tokens (Success)
 *	   NULL (Failure)
 */
char **split(char *string, const char *delim)
{
	int i, count = count_tok(string, delim);
	char *token = NULL;
	char *str_cpy = malloc(sizeof(char) * (_strlen(string) + 1));
	char **array = malloc(sizeof(char *) * count);

	_strcpy(str_cpy, string);
	token = strtok(str_cpy, delim);
	if (array == NULL)
		return (NULL);

	for (i = 0; token != NULL; i++)
	{
		array[i] = malloc(sizeof(char) * (_strlen(token) + 1));

		if (array[i] == NULL)
		{
			free(str_cpy);
			return (NULL);
		}

		array[i] = token;

		token = strtok(NULL, delim);
	}
	array[i] = NULL;
	return (array);
}

/**
 * count_tok - Counts the number of tokens in a string according to the
 * delimiters given.
 *
 * @string: Pointer to Character value, that represents the string that
 * contatins the tokens.
 * @delim: Pointer to Constant Character value, that represents the delimiter
 * that the tokens are going to be counted according to.
 *
 * Return: Positive Number (Success)
 *	   -1 (Failure)
 */
int count_tok(char *string, const char *delim)
{
	char *str_cpy, *token = NULL;
	int i;

	str_cpy = malloc(sizeof(char) * (_strlen(string) + 1));

	_strcpy(str_cpy, string);
	token = strtok(str_cpy, delim);

	/**
	 * Handling if the given string was NULL.
	 */
	if (token == NULL)
		return (-1);

	else
	{
		/**
		 * Counting the number of tokens in the given string.
		 */
		for (i = 1; token != NULL; i++)
			token = strtok(NULL, delim);

	}
	free(str_cpy);
	return (i);
}
