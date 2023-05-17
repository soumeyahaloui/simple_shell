#include "shell.h"

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
		if (n == 1)
			exit(0);
		line[n - 1] = '\0';

		if (!strcmp(line, "exit\n"))
			exit(0);

		if (!strcmp(line, "env\n"))
		{
			int i;

			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
		}

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
			printf("%s: command not found\n", args[0]);
		free(args);
		}
}
