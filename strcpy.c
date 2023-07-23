#include "main.h"

/**
 * _strcpy - Copies a string pointed to by `src` pointer including '\0'
 * to the buffer pointed to by `dest` pointer.a
 * @dest: Pointer that points to a Charcter value (string or array of chars.)
 * that the `src` pointers copies the orginal string to it.
 * @src: Pointer that points to a Character value  (string or array of chars.)
 * that it copies to `dest`.
 *
 * Return: Base address to the array of Charcaters `dest`.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
