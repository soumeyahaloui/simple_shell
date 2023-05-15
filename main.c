#include "shell.h"

/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}

/**
 * handle_input - Handles the user input
 * @info: Pointer to the info_t structure
 * @input: User input string
 */
void handle_input(info_t *info, char *input)
{
	info->line_count++;
	remove_comments(input);

	/* Handle empty lines */
	if (*input == '\n')
		return;

	set_info(info, input);
	if (replace_alias(info) == -1)
	{
		print_error(&info, "alias: not found");
		return;
	}

	if (replace_vars(info) == -1)
	{
		print_error(&info, "Illegal variable name");
		return;
	}

	if (find_builtin(&info) == 0)
		fork_cmd(&info);
}

/**
 * main - Entry point for the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: The exit status of the shell program
 */
int main(int argc, char **argv)
{
	info_t info = INFO_INIT;
	char *input = NULL;
	size_t input_size = 0;
	int exit_status = 0;

	(void)argc; /* Unused parameter */

	/* Initialize signal handler for SIGINT */
	signal(SIGINT, sigintHandler);

	/* Read and process input */
	while (1)
	{
		print_prompt();

		if (_getline(&info, &input, &input_size) == -1)
			break;

		handle_input(&info, input);

		if (info.status == 2)
			continue;
		else if (info.status == -1)
			exit_status = 2;
		else if (info.status == 3)
			exit_status = 127;
		else
			exit_status = info.status;

		clear_info(&info);
	}

	free(input);
	clear_info(&info);
	return (exit_status);
}
