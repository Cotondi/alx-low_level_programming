#include "lists.h"

/**
* reverse_listint - Reverses a listint_t linked list.
* @head: A pointer to a pointer to the head of the list.
* Returns: A pointer to the first node of the reversed list.
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *first, *rest;

if (*head == NULL)
return (NULL);

first = *head;
rest = first->next;

if (rest == NULL)
return (first);

*head = rest;

reverse_listint(head);

first->next->next = first;
first->next = NULL;

return (*head);
}
