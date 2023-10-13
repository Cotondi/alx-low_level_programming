#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
*/
void print_all(const char * const format, ...)
{
int i = 0;
char *str, *sep = "";

va_list list;

va_start(list, format);

if (format)
{
while (format[i])
{
switch (format[i])
{
case 'c':
printf("%sCharacter: %c", sep, va_arg(list, int));
break;
case 'i':
printf("%sInteger: %d", sep, va_arg(list, int));
break;
case 'f':
printf("%sFloat: %f", sep, va_arg(list, double));
break;
case 's':
str = va_arg(list, char *);
if (!str)
str = "(nil)";
printf("%sString: %s", sep, str);
break;
default:
i++;
continue;
}
sep = ", ";
i++;
}
}

printf("\n");
va_end(list);
}
