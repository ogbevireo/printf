#include "main.h"

/**
 * fs_register - registers and tracks all valid format specifiers
 * @sp: character as an input to check if it is valid specifier
 *
 * Return: bool (true or false)
 */
bool fs_register(char sp)
{
	char format_specifiers[] = {
		'c', 's', '\0'
	};
	int i;

	for (i = 0; format_specifiers[i]; i++)
	{
		if (sp == format_specifiers[i])
			return (true);
	}
	return (false);
}

/**
 * fs_buf_switcher - A helper function to aid the gen_fs_buf function
 * @sp: confirmed character as a format specifier
 * @j: index to track each FS struct in the fs_buf
 * @fs_buf: a buffer of FS structs generated in the gen_fs_buf function
 *
 * Return: void
 */

void fs_buf_switcher(char sp, int j, FS *fs_buf)
{
	switch (sp)
	{
		case 'c':
			fs_buf[j].type = 'c';
			fs_buf[j].parser = c_parser;
			break;
		case 's':
			fs_buf[j].type = 's';
			fs_buf[j].parser = s_parser;
			break;
	}
}
