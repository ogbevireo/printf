#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, va_list list)
{
	const char *p;
	int width = 0;
	
	for (p = format; *p; p++)
	{
		if (is_digit(*p))
		{
			width *= 10;
			width += *p - '0';
		}
		else if (*p == '*')
		{
			p++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	return (width);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
