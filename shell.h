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
void c_handler(int sig);
char *my_input(void);
char *my_string(char *pth, char *inp, int cnt);
char *my_check(char *inp);
int my_strlen(char *s);
int my_strcmp(char *k1, char *k2, int l);
char *my_strcpy(char *dest, char *sour);
void my_puts(char *s);
int _putchar(char c);
unsigned int _delimeter(char k, char *delm);
char *my_strtok(char *s, char *delm);

#endif /*SHELL_H*/
