#include "function_pointers.h"
#include <stdio.h>

/**
* array_iterator - Execute a provided function on each array element.
* @array: Pointer to an array of integers.
* @size: The number of elements in the array.
* @action: A pointer to the action function for each element.
*
* Return: Nothing.
**/
void array_iterator(int *array, size_t size, void (*action)(int))
{
unsigned int index;

/* Check if the array or action function is NULL */
if (array == NULL || action == NULL)
return;

/* Iterate through the array and apply the action function to each element */
for (index = 0; index < size; index++)
{
action(array[index]);
}
}
