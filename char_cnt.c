#include "shell.h"
/**
 * num_print - prints an integer to the stdout
 * @num: integer to be printed
*/
void num_print(int num)
{
	unsigned int r = num;

	if (num < 0)
	{
		_putchar('-');
		r = -r;
	}

	if ((r / 10) > 0)
		num_print(r / 10);

	_putchar(r % 10 + '\0');
}

/**
 * char_cnt - counts the number of occurrences of a character in a string
 * @strng: string to be searched
 *@ch: character to be counted
 *
 * Return: number of occurrences of ch in string
*/
int char_cnt(char *strng, char ch)
{
	int cnt = 0;

	while (*strng != '\0')
	{
		if (*strng == ch)
		{
			cnt++;
		}
		strng++;
	}
	return (cnt);
}
