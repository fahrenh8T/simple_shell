#include "shell.h"
/**
 * inp_check - checks if an input string is only whitespace
 * @inp: input string to be checked
 *
 * Return: 1 (only whitespace), 0 (otherwise)
*/
int inp_check(char *inp)
{
	int indx = 0, white = 0;

	while (inp[indx])
	{
		if (isspace(inp[indx]))
			white++;
		indx++;
	}
	if (indx == white)
	{
		free(inp);
		return (1);
	}
	return (0);
}

/**
 * main - runs a simple shell program
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 *
 * Return: 0 (success) or exit status (failure)
*/
int main(int argc, char **argv)
{
	char *inp, **cmd;
	int indx1, indx2, cnt = 1, status, exit_stt = 0;
	pid_t processID;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			my_puts("#cisfun$ ");
		if (argc)
			inp = my_input();
		if (inp == NULL)
			exit(EXIT_SUCCESS);
		else if (inp[0] == '\0')
		{
			free(inp);
			continue;
		}
		if (inp_check(inp))
			continue;
		cmd = parse_inp(inp, argv[0], cnt, exit_stt);
		cnt++;
		if (cmd == NULL)
			continue;
		processID = fork();
		if (processID == 0)
		{
			execve(cmd[0], cmd, NULL);
		}
		waitpid(processID, &status, 0);
		exit_stt = WEXITSTATUS(status);
		indx2 = 0;
		while (cmd[indx2])
			indx2++;
		for (indx1 = 0; indx1 <= indx2; indx1++)
			free(cmd[indx1]);
		free(cmd);
		free(inp);
	}
	return (0);
}
