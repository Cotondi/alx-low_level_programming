#include <stdio.h>
/**
* get_bit - Returns the value of a bit at a given index.
* @n: The number from which to get the bit.
* @index: The index (starting from 0) of the bit to get.
*
* Return: The value of bit at the specified index, or -1 if an error occurs.
*/
int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8))
{
return (-1); /* Index out of range */
}
return ((int)((n >> index) & 1));
}
