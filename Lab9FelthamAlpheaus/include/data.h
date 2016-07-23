#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Alpheaus Feltham, 0903594*/

typedef struct RestaurantInfo{
	int rating;
	char * name;
	char * foodType;
}Restaurant;

/*Creates a Restaurant
precondition: must have a valid name and food type
postcondition: Must output valid restaurant
*/
Restaurant * createRestaurant (int rating, char * name, char * foodType);

/*Deletes the restaurant
precondition: none
postcondition: must properly free and delete the contained data
*/
void deleteRestaurant (void const * input);

/*Compares the names of two restaurants
precondition: Must have two names to compare
postcondition: Must output a correct comparrison value (-1,0,1), that properly reflects the values input
*/
int compareName (void const * first, void const * second);

/*Compares the ratings of two restaurants
precondition: Must have two ratings to compare
postcondition: Must output a correct comparrison value (-1,0,1), that properly reflects the values input
*/
int compareRating (void const * first, void const *second);

/*Prints out the restaurant, its food type, and its rating
precondition: Must have values to print
postcondition: correctly print the values in the formant NAME,FOOD TYPE(RATING)
*/
void printRestaurant(void const * input);
