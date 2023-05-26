#include "shell.h"
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
 * my_input - A function that gets input
 * Return: string
 */
char *my_input(void)
{
	size_t n = 0;
	ssize_t nread;
	char *line = NULL;

	nread = getline(&line, &n, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	line[nread - 1] = '\0';
	return (line);
}

