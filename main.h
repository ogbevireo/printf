#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct format_specifier FS;

/**
 * struct format_specifier - A structure data type of format_specifier
 * @type: Type of format specifier
 * @parser: A function to a pointer that takes a va_list and
 * returns a string
 */

struct format_specifier
{
	char type;
	char *(*parser)(va_list);
};

unsigned int _strlen(char *s);
char *_realloc(char *ptr, int inc);
char *c_parser(va_list args);
char *s_parser(va_list args);
bool fs_register(char sp);
void fs_buf_switcher(char sp, int j, FS *fs_buf);
FS *gen_fs_buf(char *s, int n);
bool check_format_specifier(char *s, bool *is_percent_fs, int *i);
int num_of_vars(char *s);
char *str_parser(char *format, va_list args, int *j);
int _printf(char *format, ...);

#endif /* MAIN_H */
