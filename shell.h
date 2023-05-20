#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

int main(void);
extern char **environ;

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

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

#endif /* SHELL_H */
