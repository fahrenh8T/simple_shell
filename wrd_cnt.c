#include "shell.h"
/**
 * wrd_cnt - counts the number of words in a string
 * @text: string to be counted
 *
 * Return: number of words in text
*/
int wrd_cnt(char *text)
{
	int indx = 0, cnt = 0, inn = 0;

	while (text[indx] != '\0')
	{
		if (_space(text[indx]))
		{
			inn = 0;
		}
		else if (!inn)
		{
			inn = 1;
			cnt++;
		}
		indx++;
	}
	return (cnt + 1);
}

/**
 * _space - checks if a character is a whitespace
 * @ch: character to be checked
 *
 * Return: 1 if whitespace, 0 otherwise
*/
int _space(int ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r'
	|| ch == '\f' || ch == '\v')
		return (1);
	else
		return (0);
}
