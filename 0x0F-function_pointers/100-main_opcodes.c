#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - Prints the opcodes of its own main function.
* @argc: The number of arguments.
* @argv: An array of arguments.
*
* Return: 0 on success, 1 for incorrect number of arguments, 2 for negative bytes.
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("Error\n");
return 1;
}

int bytes = atoi(argv[1]);

if (bytes < 0)
{
printf("Error\n");
return 2;
}

unsigned char *address = (unsigned char *)main;
int i;

for (i = 0; i < bytes; i++)
{
printf("%02x", address[i]);
if (i < bytes - 1)
printf(" ");
}

printf("\n");
return 0;
}
