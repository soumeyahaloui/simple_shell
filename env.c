#include "shell.h"

/**
 * print_env - Prints the current environment
 * @info: The info struct
 *
 * Return: Always 0
 */
int print_env(info_t *info)
{
	int i;
	char **env = info->env;

	for (i = 0; env[i]; i++)
		_puts(env[i]);

	return (0);
}

/**
 * _getenv - Gets the value of a specific environment variable
 * @info: The info struct
 * @name: The name of the variable
 *
 * Return: The value of the variable if found, otherwise NULL
 */
char *_getenv(info_t *info, const char *name)
{
	int i, j;
	char *value;
	char **env = info->env;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; name[j] == env[i][j] && name[j] != '\0'; j++)
			;

		if (name[j] == '\0' && env[i][j] == '=')
		{
			value = env[i] + j + 1;
			return (value);
		}
	}

	return (NULL);
}
