#include "data.h"

Restaurant * createRestaurant (int rating, char * name, char * foodType){
	Restaurant * newRest;
	
	if((foodType == NULL) || (name == NULL)){
		printf("\nError creating restaurant, a value was empty");
		return(NULL);
	}
	
	newRest = malloc(sizeof(Restaurant));
	newRest->name = malloc(sizeof(char) * 64);
	newRest->foodType = malloc(sizeof(char) * 64);
	
	newRest->rating = rating;
	newRest->name = name;
	newRest->foodType = foodType;
	
	return(newRest);
}

void deleteRestaurant (void * input){
	Restaurant * toDelete;
	
	&toDelete = &input;
	
	if(toDelete != NULL){
		toDelete->name = NULL;
		toDelete->foodType = NULL;
		
		free(toDelete->name);
		free(toDelete->foodTpye);
		free(toDelete);
	}else{
		printf("\nNothing to delete");
	}
}

int compareName (void * first, void * second){
	Restaurant restA;
	Restaurant restB;
	
	restA = malloc(sizeof(Restaurant));
	restB = malloc(sizeof(Restaurant));
	
	memcpy(restA,first,sizeof(Restaurant));
	memcpy(restB,second,sizeof(Restaurant));
	
	output = 0;
	
	if(strcmp(restA,restB) > 0){
		return(-1);
	}else if(strcmp(restA,restB) == 0){
		return(0);
	}else if(strcmp(restA,restB) < 0){
		return(1);
	}else{
		printf("\nError comparing names");
	}
}
int compareRating (void * first, void * second){

	Restaurant restA;
	Restaurant restB;
	
	restA = malloc(sizeof(Restaurant));
	restB = malloc(sizeof(Restaurant));
	
	memcpy(restA,first,sizeof(Restaurant));
	memcpy(restB,second,sizeof(Restaurant));
	
	if(restA->rating > restB->rating){
		return(-1);
	}else if(restA->rating == restB->rating){
		return(0);
	}else if(restA->rating <restB->rating){
		return(1);
	}else{
		printf("\nError processing comparisson");
	}	
}

void * printRestaurant(Restaurant * input){
	
}