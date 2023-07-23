#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: Pointer that points to a Character value.
 *
 * Return: String Length (Always +ve or Zero).
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
