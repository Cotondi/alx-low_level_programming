#include <stdlib.h>
#include "dog.h"

/**
* _strlen - Calculate the length of a string.
* @s: String to evaluate.
*
* Return: Length of the string.
*/
int _strlen(char *s)
{
int i;
i = 0;

while (s[i] != '\0')
{
i++;
}

return (i);
}

/**
* _strcpy - Copy a string from source to destination.
* @dest: Pointer to the destination buffer.
* @src: String to be copied.
*
* Return: Pointer to the destination.
*/
char *_strcpy(char *dest, char *src)
{
int len, i;
len = 0;

while (src[len] != '\0')
{
len++;
}

for (i = 0; i < len; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';

return (dest);
}

/**
* new_dog - Create a new dog.
* @name: Name of the dog.
* @age: Age of the dog.
* @owner: Owner of the dog.
*
* Return: Pointer to the new dog (Success), NULL (Failure).
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
int len1, len2;
len1 = _strlen(name);
len2 = _strlen(owner);

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

dog->name = malloc(sizeof(char) * (len1 + 1));
if (dog->name == NULL)
{
free(dog);
return (NULL);
}
dog->owner = malloc(sizeof(char) * (len2 + 1));
if (dog->owner == NULL)
{
free(dog);
free(dog->name);
return (NULL);
}
_strcpy(dog->name, name);
_strcpy(dog->owner, owner);
dog->age = age;

return (dog);
}
