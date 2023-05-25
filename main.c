#include "shell.h"

/**
 * populate_env_list - Populates the environment list
 * @info: Information struct (unused)
 *
 * Return: 0 on success, -1 on failure
 */
int populate_env_list(info_t *info)
{
	(void)info; /* Marking the parameter as unused */

	/** Function implementation */
	return (0);
}

/**
 * read_history - Reads the command history
 * @info: Information struct (unused)
 *
 * Return: 0 on success, -1 on failure
 */
int read_history(info_t *info)
{
	(void)info; /* Marking the parameter as unused */

	/** Function implementation */
	return (0);
}

/**
 * hsh - Shell main function
 * @info: Information struct (unused)
 * @av: Argument vector (unused)
 *
 * Return: 0 on success, -1 on failure
 */
int hsh(info_t *info, char **av)
{
	(void)info; /* Marking the parameter as unused */
	(void)av;   /* Marking the parameter as unused */

	/** Function implementation */
	return (0);
}

/**
 * main - Entry point
 * @ac: Arg count
 * @av: Arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	int fd = 2;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}
