#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
* print_dog - Display details of a dog structure
* @dog_instance: Pointer to the dog structure to print
*/
void print_dog(struct dog *dog_instance)
{
if (dog_instance == NULL)
return;

if (dog_instance->name == NULL)
dog_instance->name = "(Name not provided)";
if (dog_instance->owner == NULL)
dog_instance->owner = "(Owner not specified)";

printf("Dog's Name: %s\nAge: %f\nOwner: %s\n",
dog_instance->name, dog_instance->age, dog_instance->owner);
}
