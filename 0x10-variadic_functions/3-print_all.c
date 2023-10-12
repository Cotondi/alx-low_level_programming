#include <stdarg.h>
#include <stdio.h>

/**
* print_all - Prints anything based on the format string.
* @format: A list of types of arguments passed to the function.
*/
void print_all(const char * const format, ...)
{
va_list args;
char *separator = "";
unsigned int i = 0;
char c;
va_start(args, format);

while (format && format[i])
{
c = format[i];
if (c == 'c')
{
printf("%s%c", separator, va_arg(args, int));
}
else if (c == 'i')
{
printf("%s%d", separator, va_arg(args, int));
}
else if (c == 'f')
{
printf("%s%f", separator, (float)va_arg(args, double));
}
else if (c == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
printf("%s(nil)", separator);
else
printf("%s%s", separator, str);
}

separator = ", ";
i++;
}

va_end(args);
printf("\n");
}

