#include "main.h"

/**
 * _strcmp - Compare two strings.
 *
 * @s1: Pointer to Character value, which is the first string to be compared.
 * @s2: Pointer to Character value, which is the second string to be compared.
 *
 * Return: -ve Integer value if s1 is less than s2
 *	   Zero if s1 is equal to s2
 *	   +ve Integer value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		else if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	/**
	 * The for loop was completed and final character needs to be checked
	 */
	return (s1[i] - s2[i]);
}
