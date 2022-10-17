#include "main.h"

/**
 * _printf - a function that produces output 
 * according to a format..
 * @format: character string. 
 * Return: the number of characters printed 
 * excluding the null byte used to end output to strings
 */

 
 
 
int _printf(const char *format ,...)
{ 
    const char *traverse; 
    unsigned int i; 
    char *s; 
	double db ;
	
	char outbuf[2048];
	
    va_list arg; 
    va_start(arg, format); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
			if( *traverse == '\0') 
				return 1;
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        switch(*traverse) 
        { 
			case 'f':
                    db = va_arg(arg, double);
                    sprintf(outbuf, "%f", db);
                    for(int j=0;outbuf[j]!='\0';j++){
                        putchar(outbuf[j]);
                    }
  
                break;           
		   case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        putchar(i);
                        break; 
			case 'i' :
            case 'd' : i = va_arg(arg,int);   //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break; 

			case 'b': i = va_arg(arg,unsigned int); //Fetch binary representation
                        puts(convert(i,2));
                        break; 
						
            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       //Fetch string
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break; 
        }   
    } 

    va_end(arg); 
} 


char *convert(unsigned int num, int base) 
{ 
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50]; 
    char *ptr; 

    ptr = &buffer[49]; 
    *ptr = '\0'; 

    do 
    { 
        *--ptr = Representation[num%base]; 
        num /= base; 
    }while(num != 0); 

    return(ptr); 
}
