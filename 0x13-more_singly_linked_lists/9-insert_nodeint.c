#include <stdlib.h>
#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a given position in a list.
* @head: A pointer to a pointer to the head of the list.
* @idx: The index where the new node should be added (starting from 0).
* @n: The integer value to be stored in the new node.
* Return: The address of the new node, or NULL if it fails.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *current = *head;
unsigned int i = 0;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

while (current != NULL && i < idx - 1)
{
current = current->next;
i++;
}

if (i != idx - 1)
{
free(new_node);
return (NULL);
}

new_node->next = current->next;
current->next = new_node;

return (new_node);
}
