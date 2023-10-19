#include "lists.h"
#include "stdlib.h"
#include "stddef.h"
/**
* list_len - outputs the number of elements contained in a linked list_t list.
* @h: A reference to the first node of the linked list.
* Return: The count of elements in the list.
*/
size_t list_len(const list_t *h)
{
size_t tally = 0;

for (; h != NULL; h = h->next)
{
tally++;
}

return (tally);
}
