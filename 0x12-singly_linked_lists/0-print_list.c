#include "lists.h"
int _putchar(char c);
/**
* print_list - Output the elements of a list_t list.
* @h: A pointer to the head of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_list(const list_t *h)
{
size_t node_tally = 0;
unsigned int len;
const char *str;

for (; h != NULL; h = h->next)
{
if (h->str == NULL)
{
node_tally++;
_putchar('[');
_putchar('0');
_putchar(']');
_putchar(' ');
_putchar('(');
_putchar('n');
_putchar('i');
_putchar('l');
_putchar(')');
_putchar('\n');
}
else
{
node_tally++;
_putchar('[');
len = h->len;
while (len > 0)
{
_putchar(len % 10 + '0');
len /= 10;
}
_putchar(']');
_putchar(' ');
str = h->str;
while (*str)
{
_putchar(*str);
str++;
}
_putchar('\n');
}
}

return (node_tally);
}
