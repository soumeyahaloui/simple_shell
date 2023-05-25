#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;
char *token;
<<<<<<< HEAD
=======

>>>>>>> e72ff7a148754a770d9511f3e90c5e841419156a
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'
#define INFO_INIT {NULL, 0, NULL}

void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

typedef struct info_s
{
	char *fname;
	int line_count;
	char **argv;
} info_t;

int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
int populate_env_list(info_t *);
int read_history(info_t *info);
int hsh(info_t *, char **);

#endif /* SHELL_H */
