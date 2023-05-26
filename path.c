#include "shell.h"
/**
 * my_string - A function that sets a path
 * @pth: pointer of type char
 * @inp: pointer of type char
 * @cnt: integer which is the lenght of the string
 * Return: string
 */
char *my_string(char *pth, char *inp, int cnt)
{
	int i = 0, k = 0;
	char *val;

	val = malloc(((my_strlen(pth) +
				(cnt * (my_strlen(inp) + 1))) + 1) * sizeof(char));
	val[((my_strlen(pth) +
				(cnt * (my_strlen(inp) + 1))))] = '\0';
	while (pth[i])
	{
		cnt = 0;
		if (pth[i + 1] == ':' || pth[i + 1] == '\0')
		{
			val[k] = pth[i];
			k++;
			val[k] = '/';
			k++;
			while (inp[cnt])
			{
				val[k] = inp[cnt];
				k++;
				cnt++;
			}
			k--;
		}
		else
		{
			val[k] = pth[i];
		}
		i++;
		k++;
	}
	return (val);
}
/**
 * my_check - A function that checks the path of the file
 * @inp: pointer of type char
 * Return: inp
 */
char *my_check(char *inp)
{
	char *pth, *environ_var, *val, *token, *lt;
	int i = 0, cnt = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		environ_var = environ[i];
		if (my_strcmp(environ_var, "PATH", 4)
				== 0 && environ_var[4] == '=')
		{
			i = 0;
			pth = environ_var + 5;
			cnt = count_char(pth, ':');
			val = my_string(pth, inp, cnt + 1);
			break;
		}
	}
	token = my_strtok(val, ":");
	while (token)
	{
		if (access(token, X_OK) == 0)
		{
			lt = malloc(sizeof(char) * my_strlen(token) + 1);
			lt[my_strlen(token)] = '\0';
			my_strcpy(lt, token);
			free(val);
			return (lt);
		}
	token = my_strtok(NULL, ":");
	}
	free(val);
	return (inp);
}

