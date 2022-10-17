#include "main.h"

/**
 * c_parser - parses character format specifier into string
 * @args: va_list
 *
 * Return: char *
 */
char *c_parser(va_list args)
{
	char *s; /* to hold the new string */

	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);

	s[0] = va_arg(args, int);
	s[1] = '\0';
	return (s);
}

/**
 * s_parser - parses string format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *s_parser(va_list args)
{
	return (va_arg(args, char *));
}
