#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line;
	char **args;
	int n;
	size_t len = 0;

	while (1)
	{
		printf("#cisfun$ ");
		n = getline(&line, &len, stdin);
		line[n - 1] = '\0';

		args = malloc(100 * sizeof(char *));
		int argc = 0;

		char *token = strtok(line, " ");

		while (token)
		{
			args[argc++] = token;
			token = strtok(NULL, " ");
		}
		args[argc] = NULL;

		if (execvp(args[0], args) == -1)
			printf("%s: No such file or directory\n", args[0]);
		free(args);
	}
}
