#include <stdio.h>

/**
* print_binary - Prints the binary representation of an unsigned long int.
* @n: The number to be converted and printed in binary.
*/
void print_binary(unsigned long int n)
{
int shift = 0;
int size = sizeof(unsigned long int) * 8;
int bit;
{
size--;
bit = (n >> size) &1;
if (bit || shift)
{
putchar(bit + '0');
shift = 1;
}
}

if (!shift)
{
putchar('0');
}
}
