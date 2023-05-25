#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point for the program
 *
 * This function reads input from the user, tokenizes it into arguments,
 * and executes commands using execvp.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	char **args;
	int n;
	size_t len = 0;
	int argc = 0;
<<<<<<< HEAD
=======
	char *token;
>>>>>>> 40aad4a7ebdee307a78b4e3e0429969ed1911139

	while (1)
	{
		printf("#cisfun$ ");
		n = getline(&line, &len, stdin);
		line[n - 1] = '\0';
		args = malloc(100 * sizeof(char *));
		argc = 0;
		token = strtok(line, " ");

		while (token)
		{
			args[argc++] = token;
			char *token;
			token = strtok(line, " ");

		}
		args[argc] = NULL;
		if (execvp(args[0], args) == -1)
			printf("%s: No such file or directory\n", args[0]);
		free(args);
	}
	free(line);
	return (0);
}
