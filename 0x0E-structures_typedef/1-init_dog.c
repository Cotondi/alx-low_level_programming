#include <stdlib.h>
#include <string.h> /* Include the string.h header for strlen and strcpy */
#include "dog.h"

/**
* init_dog - initializes a variable of type struct dog
* @d: pointer to struct dog to initialize
* @name: name to initialize
* @age: age to initialize
* @owner: owner to initialize
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
return;

d->name = malloc(strlen(name) + 1); /* Use strlen */
d->owner = malloc(strlen(owner) + 1); /* Use strlen */

if (d->name == NULL || d->owner == NULL)
{
free(d->name);
free(d->owner);
return;
}

strcpy(d->name, name); /* Use strcpy */
strcpy(d->owner, owner); /* Use strcpy */

d->age = age;
}
