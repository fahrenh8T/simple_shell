#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

int exit_chckr(char *cmd, char *inp, char *arg, int status);
char **parse(char *strng, char *inp, int cnt, char *separator, int flag);

#endif /*SHELL_H*/
