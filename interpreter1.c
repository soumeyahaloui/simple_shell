#include "shell.h"

/**
 * read_command - Read a command from the user
 * @buffer: The buffer to store the command
 * @size: The size of the buffer
 * Return: The number of characters read, or -1 on failure
 */
ssize_t read_command(char *buffer, size_t size)
{
	ssize_t nread;

	nread = getline(&buffer, &size, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
			printf("\n"); /* Add a newline if Ctrl+D is pressed */
		perror("getline");
	}

	return (nread);
}

/**
 * shell_loop - The main shell loop
 */
void shell_loop(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	do

	{
		display_prompt();
		nread = read_command(command, bufsize);
		if (nread > 0)
		{
			command[nread - 1] = '\0'; /* Remove the newline character */
			parse_command(command);
		}
	} while (nread != -1);
}

/**
 * main - Entry point of the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 * Return: The exit status of the program
 */
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	shell_loop();

	return (EXIT_SUCCESS);
}
