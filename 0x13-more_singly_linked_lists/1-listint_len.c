#include "lists.h"
#include <stdio.h>
/**
*listint_len - counts the number of elements in a linked listint_t list.
*@h: pointer to the first node.
*Return: number of elements in linked listint_t.
*/
size_t listint_len(const listint_t *h)
{
size_t tally = 0;
for (; h != NULL; h = h->next)
{
tally++;
}
return (tally);
}
