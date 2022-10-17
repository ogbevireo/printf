#include "main.h"

/**
 * _strlen - A function that returns length of a string
 * @s: The string to be checked
 * Return: The length of the string
 */

unsigned int _strlen(char *s)
{
	int i = 0;

	for (; s[i]; i++)
		;
	return (i);
}

/**
 * _realloc - A function that reallocates size to a string
 *
 * @ptr: A pointer to the memory previously allocated with
 * a call to malloc
 *
 * @inc: Size of new string
 *
 * Return: The size of the new string
 */

char *_realloc(char *ptr, int inc)
{
	unsigned int i;
	char *p = malloc(sizeof(char) * inc);

	if (!p)
		return (NULL);
	for (i = 0; i < _strlen(ptr); i++)
	{
		p[i] = ptr[i];
	}
	free(ptr);
	return (p);
}
