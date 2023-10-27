#include <stddef.h>  /* For NULL definition */

/**
* binary_to_uint - Converts a binary number represented as a string to an
* unsigned int.
* @b: A pointer to the binary string containing '0' and '1' characters.
*
* Return: The converted unsigned integer, or 0 if there are invalid
* characters in the string or if the string is NULL.
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;
int i;
if (b == NULL)
return (0);
for (i = 0; b[i] != '\0'; i++)
{
if (b[i] != '0' && b[i] != '1')
{
return (0); /* Return 0 if a character is not '0' or '1' */
}
result = (result * 2) + (b[i] - '0'); /* Shift left and add the binary digit */
}
return (result);
}
