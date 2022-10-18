#include "main.h"

/**
 * get_length - Calculates the length to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: length.
 */
int get_length(const char *format)
{
	const char *p = format;	
	int length = 0;

	if (*p == 'l')
	{
		length = 8;
		p++;
	}	
	else if (*p == 'h')
	{
		length = 2;
		p++;
	}	

	format = p;	
	return (length);
}
