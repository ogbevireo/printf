#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int minus;
	int zero;
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_int(va_list l, flags_t *f, int width, int precision, int length);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f, int width, int precision, int length);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *f, int width, int precision, int length);
int print_hex_big(va_list l, flags_t *f, int width, int precision, int length);
int print_binary(va_list l, flags_t *f, int width, int precision, int length);
int print_octal(va_list l, flags_t *f, int width, int precision, int length);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list , flags_t *, int , int , int );

/* get_flag */
int get_flag(char s, flags_t *f);

/* get_precision */
int get_precision(const char *format, va_list list);

/* get_width */
int get_width(const char *format, va_list list);
int is_digit(char c);

/* get_length */
int get_length(const char *format);

/* print_alpha */
int print_string(va_list l, flags_t *f, int width, int precision, int length);
int print_char(va_list l, flags_t *f, int width, int precision, int length);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f, int width, int precision, int length);
int print_rev(va_list l, flags_t *f, int width, int precision, int length);
int print_bigS(va_list l, flags_t *f, int width, int precision, int length);

/* print_address */
int print_address(va_list l, flags_t *f, int width, int precision, int length);

/* print_percent */
int print_percent(va_list l, flags_t *f, int width, int precision, int length);

#endif
