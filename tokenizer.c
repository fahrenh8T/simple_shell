#include "shell.h"
/**
 * _delimeter - a delemiter function for tokenizing
 * @k: character
 * @delm: pointer to a delimeter
 * Return: 0
 */
unsigned int _delimeter(char k, char *delm)
{
	while (*delm != '\0')
	{
		if (k == *delm)
			return (1);
		delm++;
	}
	return (0);
}
/**
 * my_strtok - function that works like strtok
 * @s: pointer to a string
 * @delm: pointer to a delimeter
 * Return: The string
 */
char *my_strtok(char *s, char *delm)
{
	static char *str, *r;

	if (!s)
		s = str;
	if (!s)
		return (NULL);
	while (1)
	{
		if (_delimeter(*s, delm))
		{
			s++;
			continue;
		}
		if (*s == '\0')
			return (NULL);
		break;
	}
	r = s;

	while (1)
	{
		if (*s == '\0')
		{
			str = s;
			return (r);
		}
		if (_delimeter(*s, delm))
		{
			*s = '\0';
			str = s + 1;
			return (r);
		}
		s++;
	}
}
