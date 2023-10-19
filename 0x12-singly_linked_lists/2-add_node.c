#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node - Inserts a new node at the start of a list_t list.
* @head: A reference to a double-pointer pointing to the list's beginning.
* @str: The string to be added to the new node.
*
* Return: The address of the new element, or NULL if it failed.
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;

if (str == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->len = strlen(str);
new_node->next = *head;
*head = new_node;

return (new_node);
}
