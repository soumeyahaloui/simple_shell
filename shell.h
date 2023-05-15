#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

/**
 * struct info_s - Structure containing file descriptors
 * @readfd: The file descriptor for reading input
 * @errorfd: The file descriptor for writing error messages
 *
 * Description: This structure contains the file descriptors used by the shell.
 */
typedef struct info_s
{
	int readfd;
	int errorfd;
} info_t;

int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

#endif /* SHELL_H */
