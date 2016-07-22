#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RestaurantInfo{
	int rating;
	char * name;
	char * foodType;
}Restaurant;

Restaurant * createRestaurant (int rating, char * name, char * foodType);

void deleteRestaurant (Restaurant * input);

int compareName (void const * first, void const * second);

int compareRating (void const * first, void const *second);

void printRestaurant(void * input);
