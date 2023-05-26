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
 * @command: The command to executed
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *args[MAX_ARGS] = {NULL};
	char *token = strtok(command, " ");

	for (int i = 0; token && i < MAX_ARGS; i++, token = strtok(NULL, " "))
		args[i] = token;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}

	while (waitpid(pid, &status, WUNTRACED) == -1);
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
