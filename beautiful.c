#include "shell.h"

/**
 * interactive - Check if shell is running in interactive mode
 * @info: Pointer to the info_t structure
 *
 * Return: 1 if running in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	if (isatty(STDIN_FILENO) && info->readfd <= 2)
		return (1);

	return (0);
}

/**
 * is_delim - Check if a character is a delimiter
 * @c: The character to check
 * @delim: The string of delimiters
 *
 * Return: 1 if character is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}

	return (0);
}

/**
 * _isalpha - Check if an integer represents an alphabetic character
 * @c: The integer to check
 *
 * Return: 1 if integer represents an alphabetic character, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);

	return (0);
}

/**
 * _atoi - Convert a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int flag = 0;
	int output = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			flag = 1;
		}
		else if (flag == 1)
			break;

		s++;
	}

	output = (sign == -1) ? -result : result;
	return (output);
}
