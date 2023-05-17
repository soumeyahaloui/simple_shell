#include <stdlib.h>
#include <stdio.h>

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line;
	size_t len = 0;
	int n;

	while (1)
	{
		printf("#cisfun$ ");
		n = getline(&line, &len, stdin);

		if (n <= 0)
			exit(0);

		line[n - 1] = '\0';

		if (execve(line, NULL, NULL) == -1)
			printf("%s: No such file or directory\n", line);
	}
}
