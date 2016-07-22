#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
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

int compareName (void * first, void * second);

int compareRating (void * first, void * second);

void printRestaurant(void * input);

#endif