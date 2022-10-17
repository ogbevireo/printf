#include <unistd.h>
#include "main.h"

/**
 * _printf - a function that produces output 
 * according to a format..
 * @format: character string. 
 * Return: the number of characters printed 
 * excluding the null byte used to end output to strings
 */

int _printf(const char *format)
{
	int i=0,j=0;
	int space=0;
	if( format[i] == '"')
	{
		i++;
		while( format[i] != '"')
		{
			if( format[i] == '%')
			{
				i++;
				switch(format[i])
				{
					case 'c': break;
					case 's': break;
					case '%': _putchar('%');j++; break;
					case '0': space= 0;i++; break;
					case '1': space= 1;i++; break;
					case '2': space= 2;i++; break;
					case '3': space= 3;i++; break;
					case '4': space= 4;i++; break;
					case '5': space= 5;i++; break;
					case '6': space= 6;i++; break;
					case '7': space= 7;i++; break;
					case '8': space= 8;i++; break;
					case '9': space= 9;i++; break;
					default: Error("Error : Format is invalid ..."); break;
				}
			}
			else if( format[i] == '\')
			{
				i++;
				switch(format[i])
				{
					case 'n': _putchar('\n');j++;break;
					case 'a': break;
					case 'b': break;
					case 'f': break;
					case 'r': break;
					case 't': break;
					case 'v': break;
					case '%': _putchar('%');j++; break;
					case '"': _putchar('"');j++; break;
					default : _putchar('\\');j++; _putchar(format[i]);j++; break;
				}
			}
			else
			{
				_putchar(format[i]);
				j++;
			}
			i++;
		}
	}else{
		/*Error invalid format*/
		Error("Error : Format is invalid ...");
	}
	
	return j;
}
