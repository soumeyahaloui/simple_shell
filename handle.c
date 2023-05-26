#include "shell.h"

/**
 * hsh - Execute a command in a child process
 * @args: Array of strings representing the command and its arguments
 *
 * Return: Always returns 1
 */
int hsh(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Fork error */
		perror("fork");
	}
	else
	{
		/* Parent process */
		do

		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * main - Entry point of the program
 *
 * Return: Always returns 0
 */
int main(void)
{
	char *args[] = {"/bin/ls", "-l", NULL}; /* Example command: ls -l */

	hsh(args);

	return (0);
}
