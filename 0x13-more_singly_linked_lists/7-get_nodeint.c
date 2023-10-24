#include <stdlib.h>
#include "lists.h"

/**
* get_nodeint_at_index - Returns the nth node of a listint_t linked list.
* @head: A pointer to the head of the list.
* @index: The index of the node to retrieve (starting at 0).
*
* Return: The node at the specified index, or NULL if it doesn't exist.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int count = 0;
listint_t *current = head;

while (current != NULL)
{
if (count == index)
return (current);
count++;
current = current->next;
}

return (NULL);
}
