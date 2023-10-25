#include "lists.h"
#include <stdio.h>
/**
* print_listint - prints all elements of link.
* @h: linked list of listint_t type.
*
* Return: the number of nodes.
*/
size_t print_listint(const listint_t *h)
{
size_t tally = 0;
while (h)
{
printf("%d\n", h->n);
h = h->next;
tally++;
}
return (tally);
}
