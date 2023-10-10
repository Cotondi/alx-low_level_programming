#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
* _strlen - returns the length of a string
* @s: string to evaluate
*
* Return: the length of the string
*/
int _strlen(char *s)
{
int length = 0;
while (s[length] != '\0')
{
length++;
}
return (length);
}

/**
* _strcpy - copies the string pointed to by src
* including the terminating null byte (\0)
* to the buffer pointed to by dest
* @dest: pointer to the buffer in which we copy the string
* @src: string to be copied
*
* Return: the pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
* free_dog - frees memory allocated for a struct dog
* @d: struct dog to free
*/
void free_dog(dog_t *d)
{
if (d)
{
free(d->name);
free(d->owner);
free(d);
}
}
