#include <stdlib.h>
#include "lists.h"

/**
* free_list - Frees a list_t list.
* @head: A pointer to the head of the list.
*/
void free_list(list_t *head)
{
list_t *current;

for (current = head; current != NULL;)
{
head = current->next;
free(current->str);
free(current);
current = head;
}
}
