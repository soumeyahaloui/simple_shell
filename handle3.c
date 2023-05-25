#include "shell.h"

#define CONVERT_UNSIGNED 1
#define CONVERT_LOWERCASE 2

/**
 * convert_number - converts a number to a string in the specified base
 * @num: the number to convert
 * @base: the base of the conversion
 * @flags: argument flags
 *
 * Return: the converted string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do

	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * remove_comments - replaces the first instance of '#' with '\0' in a string
 * @buf: the string to modify
 *
 * Return: Nothing
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
