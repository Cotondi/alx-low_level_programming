#include "function_pointers.h"

/**
* find_index - the index of an element in an integer array meeting a condition.
* @arr: Pointer to an integer array.
* @size: Number of elements in the array.
* @condition: Pointer to a user-defined condition  function.
*
* Return: Index of the first element meeting the condition, or -1 if no match is found.
*/
int find_index(int *arr, int size, int (*condition)(int))
{
int i;

if (!arr || size <= 0 || !condition)
return (-1);

for (i = 0; i < size; i++)
if (condition(arr[i]))
return (i);

return (-1);
}
