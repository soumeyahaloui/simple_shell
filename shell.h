#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void);
extern char **environ;

#endif /* SHELL_H */
