#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	printf("$ "); /* Customize the prompt as desired */
}

/**
 * execute_command - Execute the given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* Child process */
	{
		char *args[] = {command, NULL};

		execvp(command, args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else /* Parent process */
	{
		do

		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * parse_command - Parse the command and execute it
 * @command: The command to parse and execute
 */
void parse_command(char *command)
{
	if (strcmp(command, "exit") == 0)
		exit(EXIT_SUCCESS);

	execute_command(command);
}
