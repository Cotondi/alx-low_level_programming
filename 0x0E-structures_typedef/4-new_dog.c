#include <stdlib.h>
#include "dog.h"

/**
* new_dog - Create a new dog structure
* @name: The name of the dog
* @age: The age of the dog
* @owner: The owner of the dog
*
* Return: A pointer to the new dog structure (Success), NULL otherwise
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
int name_length, owner_length;

name_length = _strlen(name);
owner_length = _strlen(owner);

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

dog->name = malloc(sizeof(char) * (name_length + 1));
if (dog->name == NULL)
{
free(dog);
return (NULL);
}

dog->owner = malloc(sizeof(char) * (owner_length + 1));
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
