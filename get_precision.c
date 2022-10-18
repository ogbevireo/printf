#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, va_list list)
{
	const char *p = format;
	int precision = -1;

	if (*p != '.')
		return (precision);

	precision = 0;

	for (p = p+1; *p; p++)
	{
		if (is_digit(*p))
		{
			precision *= 10;
			precision += *p - '0';
		}
		else if (*p == '*')
		{
			p++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	return (precision);
}
