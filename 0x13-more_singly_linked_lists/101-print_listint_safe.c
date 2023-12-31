#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list safely.
* @head: A pointer to the head of the list.
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current = head;
const listint_t *loop_start = NULL;
size_t count = 0;

while (current != NULL)
{
printf("[%p] %d\n", (void *)current, current->n);
count++;

if (current < current->next)
{
current = current->next;
}
else
{
if (loop_start == NULL)
loop_start = current;
current = current->next;
if (current == loop_start)
{
printf("-> [%p] %d\n", (void *)current, current->n);
count++;
break;
}
}
}

if (loop_start != NULL)
exit(98);

return (count);
}
