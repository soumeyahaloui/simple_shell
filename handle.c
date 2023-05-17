#include <shell.h>

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;
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
		char *path = getenv("PATH");
		char *command_path = NULL;

		token = strtok(path, ":");
		while (token)
		{
			command_path = malloc(strlen(token) + strlen(args[0]) + 2);
			sprintf(command_path, "%s/%s", token, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				break;
			}
			free(command_path);
			command_path = NULL;
			token = strtok(NULL, ":");
		}
		if (command_path == NULL)
		{
			printf("%s: command not found\n", args[0]);
		}
		else
		{
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{
				execve(command_path, args, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				int status;

				waitpid(child_pid, &status, 0);
			}
			free(command_path);
		}
		free(args);
	}
	free(line);
	return 0;
}
