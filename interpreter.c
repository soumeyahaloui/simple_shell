#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char **environ;
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	while (1)
	{
		printf("#cisfun$ ");
		n = getline(&line, &len, stdin);

		if (n == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		line[n - 1] = '\0';

		if (execve(line, (char *[])
					{line, NULL}, environ) == -1)
		{
			printf("%s: No such file or directory\n", line);
		}
	}

	free(line);
	return (EXIT_SUCCESS);
}
