#include "shell.h"

/**
 * main - Entry point
 * @ac: Arg count
 * @av: Arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	void populate_env_list(info_t *info);
	void read_history(info_t *info);
	void hsh(info_t *info, char **av);

	info_t info[] = {INFO_INIT};
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
		info[0].line_count = fd;
	}

	populate_env_list(info); /** Pass the address of info */
	read_history(info); /**  Pass the address of info */
	hsh(info, av);

	return (EXIT_SUCCESS);
}
