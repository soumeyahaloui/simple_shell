#include "shell.h"

/**
 * _eputs - Prints a string to the standard error
 * @str: The string to print
 */
void _eputs(char *str)
{
	while (*str != '\0')
	{
		_eputchar(*str);
		str++;
	}
}

/**
 * _eputchar - Writes a character to the standard error
 * @c: The character to write
 * Return: On success 1, on error -1
 */
int _eputchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * _putfd - Writes a character to a file descriptor
 * @c: The character to write
 * @fd: The file descriptor
 * Return: On success 1, on error -1
 */
int _putfd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * _putsfd - Writes a string to a file descriptor
 * @str: The string to write
 * @fd: The file descriptor
 * Return: On success the number of characters written, on error -1
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (_putfd(str[i], fd) == -1)
			return (-1);
		i++;
	}
	return (i);
}
