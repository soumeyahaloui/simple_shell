#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define INFO_INIT { 0, 0, 0 }

/**
 * struct info_s - Information structure for the shell
 * @readfd: File descriptor for reading input
 * @line_count: Number of lines in the shell
 * @status: Status of the shell
 */
typedef struct info_s
{
	int readfd;
	int line_count; /* Number of lines in the shell */
	int status; /* Status of the shell */
} info_t;

void _puts(const char *str);
void remove_comments(char *str);
void set_info(info_t *info, char *input);
int replace_alias(info_t *info);
void print_error(info_t **info, const char *message);
int replace_vars(info_t *info);
int find_builtin(info_t **info);
void fork_cmd(info_t **info);
ssize_t _getline(info_t *info, char **lineptr, size_t *n);
void clear_info(info_t *info);
void sigintHandler(int sig_num);
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

#endif /* _SHELL_H_ */
