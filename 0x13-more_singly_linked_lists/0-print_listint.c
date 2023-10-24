#include <stdio.h>
#include "lists.h"
/**
*print_listint -  prints the number of elements in a listint_t list.
*@h: a pointer to the first node.
*
* Return: the total number of nodes in the list.
*/
size_t print_listint(const listint_t *h)
{
size_t node_tally = 0;
for (; h != NULL; h = h->next)
{
printf("%d\n", h->n);
node_tally++;
}
return (node_tally);
}

