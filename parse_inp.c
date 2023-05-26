#include "shell.h"
/**
 * exit_chckr - checks if the user inpt matches the exit command
 * @cmd: user input string
 * @inp: user input as an array of string
 * @store: buffer used to store the user input
 * @status: exit status of the previous command
 *
 * Return: 0 if user input does not match the exit command
 * or exit wit status or 69 if too many arguments
*/
int exit_chckr(char *cmd, char *inp, char *store, int status)
{
	int i = 0, k = 0;
	char *exit_cmd = "exit";

	while (cmd[i] == exit_cmd[i])
		i++;

	k = wrd_cnt(inp);
	if (k > 2 && i == 5)
	{
		free(store);
		free(inp);
		exit(69);
	}

	if (i == 5)
	{
		free(store);
		free(inp);
		exit(status);
	}
	return (0);
}

/**
 * parse - parses a string into an array of strings using a separator
 * @strng: string to be parsed
 * @inp: string to be tokenized
 * @cnt: number of elements in array
 * @separator: separator to be used for parsing
 * @flag: flag to indicate whether to free the separator or not
 *
 * Return: a pointer to the array of srtings or NULL (failure)
*/
char **parse(char *strng, char *inp, int cnt, char *separator, int flag)
{
	char **rslt;
	int i = 0;

	rslt = malloc(sizeof(char *) * cnt);
	while (i < cnt)
	{
		rslt[i] = NULL;
		i++;
	}

	i = 0;
	cnt = 0;
	if (flag > 0)
		free(separator);
	while (separator)
	{
		if (cnt == 0)
		{
			rslt[cnt] = malloc(sizeof(char) * my_strlen(strng) + 1);
			rslt[cnt][my_strlen(strng)] = '\0';
			my_strcpy(rslt[cnt], strng);
		}
		if (cnt != 0)
		{
			rslt[cnt] = malloc(sizeof(char) * my_strlen(separator) + 1);
			rslt[cnt][my_strlen(separator)] = '\0';
			my_strcpy(rslt[cnt], separator);
		}

		cnt++;
		if  (i == 0)
		{
			separator = my_strtok(inp, "\t");
		}
		separator = my_strtok(NULL, "\t");
		i++;
	}
	return (rslt);
}

/**
 * err_print - prints an error message to the stdout
 * @flname: name of the file where the error occurred
 * @tkn: tokn that caused the error
 * @num: line number where the error occurred
*/
void err_print(char *flname, char *tkn, int num)
{
	my_puts(flname);
	my_puts(": ");
	num_print(num);
	my_puts(": ");
	my_puts(tkn);
	my_puts(": not found\n");
}

/**
 * parse_inp - parse an input string into an array of strings using a token
 * @inp: input string to be parsed
 * @flname: name of the file where input came from
 * @lcnt: line number where the input was read
 * @status: exit status of the previous command
 *
 * Return: pointer to the array of strings or NULL (failure) or exit
*/
char **parse_inp(char *inp, char *flname, int lcnt, int status)
{
	int cnt = 0, lngth = 0, indx = 0, execflg = 0;
	char *tkn, *store, *cmd = "env", *cmd_strng, **grid;

	cnt = wrd_cnt(inp);
	while (inp[lngth])
		lngth++;
	store = malloc(sizeof(char) * lngth + 2);
	store[lngth + 1] = '\0';
	my_strcpy(store, inp);
	store[my_strlen(inp)] = ' ';
	tkn = my_strtok(store, "\t ");
	if (exit_chckr(tkn, inp, store, status))
		return (NULL);
	while  (tkn[indx] == cmd[indx])
		indx++;
	if (indx == 4)
	{
		env_inp(store, inp);
		return (NULL);
	}
	if (access(tkn, X_OK) == -1)
	{
		tkn = my_check(tkn);
		execflg++;
	}
	cmd_strng = malloc(my_strlen(tkn) + 1);
	cmd_strng[my_strlen(tkn)] = '\0';
	my_strcpy(cmd_strng, tkn);
	if (access(cmd_strng, X_OK) == -1)
	{
		free(tkn);
		err_print(flname, cmd_strng, lcnt);
		free(cmd_strng);
		free(inp);
		return (NULL);
	}
	grid = parse(cmd_strng, inp, cnt, tkn, execflg);
	free(store);
	free(cmd_strng);
	return (grid);
}
