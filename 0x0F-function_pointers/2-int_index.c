#include "function_pointers.h"

/**
* int_index - Find index of element in an integer array based on a condition.
* @array: Array of integers.
* @size: Size of elements in the array.
* @cmp: Pointer to a condition-checking function.
*
* Return: (-1) if no match is found, or index of the first matching element.
*/
int int_index(int *array, int size, int (*cmp)(int))
{
int i;

if (array == NULL || size <= 0 || cmp == NULL)
return (-1);

for (i = 0; i < size; i++)
if (cmp(array[i]))
return (i);

return (-1);
}
