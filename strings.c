#include "shell.h"
/**
 * my_strlen - A function that returns the length of a string
 * @s: pointer to a string
 *
 * Return: integer
 */
int my_strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;
	return (i);
}

/**
 * my_strcmp - A function that performs comparison of two strings.
 * @k1: pointer to the first string
 * @k2: pointer to the second string
 * @l: length of comparison
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int my_strcmp(char *k1, char *k2, int l)
{
	int i = 0;

	while (k1[i] && k2[i] && l >= i)
	{
		if (*k1 != *k2)
			return (*k1 - *k2);
		k1++;
		k2++;
		i++;
	}
	if (*k1 == *k2)
		return (0);
	else
		return (*k1 < *k2 ? -1 : 1);
}
/**
 * my_strcpy - copies a string
 * @dest: pointer to the destination
 * @sour: pointer to the source
 * Return: destination
 */
char *my_strcpy(char *dest, char *sour)
{
	int i = 0;

	if (dest == sour || sour == 0)
		return (dest);
	while (sour[i])
	{
		dest[i] = sour[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * my_puts - a function taht prints an input string
 * @s: the string to be printed
 * Return: Nothing
 */
void my_puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
return;
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

