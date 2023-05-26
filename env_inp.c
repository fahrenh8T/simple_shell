#include "shell.h"
/**
 * env_inp - prints the environment varibale to the stdout
 * @strng: string to be freed
 * @inp: input to be freed
 *
 * Return: 0 (success)
*/
int env_inp(char *strng, char *inp)
{
	int indx = 0;

	while (environ[indx])
	{
		puts(environ[indx]);
		indx++;
	}
	free(strng);
	free(inp);
	return (0);
}
