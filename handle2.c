#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 Return 0 if no numbers, else return the converted number.
 *         -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');

			if (result > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}

	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter and return info struct
 * @estr: string containing the specified error type
 *
 * Return: Nothing
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - prints a decimal (integer) number (base 10)
 * @input: the input number
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = __putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
	{
		_abs_ = input;
	}

	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}

		current %= i;
	}

	__putchar('0' + current);
	count++;

	return (count);
}
