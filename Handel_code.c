#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * parseInput - Tokenize the input line into arguments
 * @line: Input line to be tokenized
 * @args: Array to store the arguments
 * @argSize: Maximum size of the argument array
 *
 * Return: Number of arguments parsed
 */
int parseInput(char *line, char **args, int argSize)
{
	char *token;
	int argc = 0;

	token = strtok(line, " ");
	while (token != NULL && argc < argSize - 1)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " ");
	}
	args[argc] = NULL;

	return (argc);
}
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
	char *args[100];
	size_t len = 0;
	ssize_t nread;
	int argc;

	while (1)
	{
		printf("#cisfun$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("getline");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		argc = parseInput(line, args, 100);

		if (argc > 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror(args[0]);
			}
		}
	}

	free(line);
	return (0);
}
