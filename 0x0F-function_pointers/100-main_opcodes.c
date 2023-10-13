#include <stdio.h>
#include <stdlib.h>

/**
* main - Prints the opcodes of its own main function.
* @argc: The number of arguments.
* @argv: An array of argument strings.
*
* Return: 0 on success, 1 for incorrect arguments, 2 for negative bytes.
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("Error\n");
return (1);
}

int num_bytes = atoi(argv[1]);

if (num_bytes < 0)
{
printf("Error\n");
return (2);
}

unsigned char *main_ptr = (unsigned char *)main;
int i;

for (i = 0; i < num_bytes; i++)
{
printf("%02x", main_ptr[i]);
if (i < num_bytes - 1)
printf(" ");
}
printf("\n");

return (0);
}
