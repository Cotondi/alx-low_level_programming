#include <stdlib.h>
#include <stdio.h>
/**
**malloc checked - Allocate memory using malloc and check for failure
*@b: The number of bytes to allocate.
*
*
* main - Entry point of the program.
* It demonstrates the usage of the malloc_checked function.
*Return: Always returns 0.
*
*/
void *malloc_checked(unsigned int b)
{
void *ptr = malloc(b);
if (ptr == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(98);
}
return (ptr);
}
int main(void)
{
unsigned int size = 10;
int *array = (int *)malloc_checked(size * sizeof(int));
free(array);
return (0);
}
