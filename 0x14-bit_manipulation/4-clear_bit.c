#include <stdio.h>
#include "main.h"
/**
* clear_bit - Sets the value of a bit to 0 at a given index.
* @n: A pointer to the unsigned long int to modify.
* @index: The index (starting from 0) of the bit to set to 0.
*
* Return: 1 if it worked, or -1 if an error occurred.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
{
return (-1); /* Index out of range */
}
*n = *n & ~(1UL << index); /* Set the bit at the specified index to 0 */
return (1);
}
