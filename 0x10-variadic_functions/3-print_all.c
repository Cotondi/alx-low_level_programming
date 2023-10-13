#include <stdio.h>
#include <stdarg.h>

/**
* print_all - Prints values based on a given format string.
* @format: A string containing format specifiers.
*             'c' for char, 'i' for integer, 'f' for float, 's' for string.
*/
void print_all(const char * const format, ...)
{
va_list args;
char *str;
int i = 0;
char format_char;

va_start(args, format);

while (format && format[i])
{
format_char = format[i];
switch (format_char)
{
case 'c':
printf("%c", va_arg(args, int));
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(nil)";
printf("%s", str);
break;
}

if ((format[i + 1] != '\0') && (format_char == 'c' || format_char == 'i' ||
format_char == 'f' || format_char == 's'))
printf(", ");
i++;
}

va_end(args);
printf("\n");
}
