#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer that points to a Character value, where the `src`
 * string should be concatenated to.
 * @src: Pointer that points to a Character value, where it contains
 * the string that should be concatenated to `dest`.
 *
 * Return: Base Address of `dest`.
 */

char *_strcat(char *dest, char *src)
{
	int len_src = _strlen(src);
	int i_dest = _strlen(dest);
	int len_t = len_src + i_dest;
	int i_src = 0;

	for (; i_dest <= (len_t - 1); i_dest++)
	{
		dest[i_dest] = src[i_src];
		i_src++;
	}

	dest[i_dest] = '\0';

	return (dest);
}
