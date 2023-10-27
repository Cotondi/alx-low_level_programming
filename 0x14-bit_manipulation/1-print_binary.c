#include <stdio.h>
#include "main.h"
/**
* print_binary - Prints the binary representation of an unsigned long int.
* @n: The number to be converted and printed in binary.
*/
void print_binary(unsigned long int n)
{
int bit_count = sizeof(n) * 8;
int shift = 0;
if (n == 0)
{
putchar('0');
return;
}

while (bit_count > 0)
{
int bit = (n >> (bit_count - 1)) & 1;
if (bit || shift)
{
putchar(bit + '0');
shift = 1;
}
bit_count--;
}
}
