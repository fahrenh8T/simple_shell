#include "shell.h"
#define MAX_LENGTH 1024
/**
 * c_handler - a function handles ctrl + c when entered by the user
 * @sig: SIGINT
 */
void c_handler(int sig)
{
	(void)sig;
	my_puts("\n");
	my_puts("$ ");
}
/**
 * my_input - my own getline function
 * Return: string
 */
char *my_input(void)
{
	static char buff[MAX_LENGTH];
	static int buff_index;
	static int n;
	char *line = NULL;
	int index = 0;

	while (1)
	{
		if (buff_index == n)
		{
			n = read(STDIN_FILENO, buff, MAX_LENGTH);
			buff_index = 0;
			if (n == 0)
				break;
		}
		while (buff_index < n && buff[buff_index] != '\n')
		{
			if (buff[buff_index] == '\r')
			{
				buff_index++;
				continue;
			}
			if (!line)
			{
				line = malloc(MAX_LENGTH * sizeof(char));
			}
			line[index++] = buff[buff_index++];
		}
		if (buff_index < n && buff[buff_index] == '\n')
		{
			line[index] = '\0';
			buff_index++;
			break;
		}
	}
	return (line);
}

