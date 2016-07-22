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

void deleteRestaurant (Restaurant * input){
	Restaurant * toDelete;
	
	toDelete = input;
	
	if(toDelete != NULL){
		toDelete->name = NULL;
		toDelete->foodType = NULL;
		
		free(toDelete->name);
		free(toDelete->foodType);
		free(toDelete);
	}else{
		printf("\nNothing to delete");
	}
}

int compareName (void const * first, void const * second){
	Restaurant * restA;
	Restaurant * restB;
	
	restA = malloc(sizeof(Restaurant));
	restB = malloc(sizeof(Restaurant));
	
	if((first != NULL) && (second != NULL)){
		memcpy(restA,first,sizeof(Restaurant));
		memcpy(restB,second,sizeof(Restaurant));
	}else{
		if(first == NULL){
			printf("\nCurrent Branch was NULL");
		}else if (first != NULL){
			printf("\nCurrent Branch was not NULL");
		}
		if(second == NULL){
			printf("\nData to be added was NULL");
		}else if (second != NULL){
			printf("\nData to be added was not NULL");
		}
		printf("\nError copying Data");
		exit(0);
	}
	
	if(strcmp(restA->name,restB->name) > 0){
		return(-1);
	}else if(strcmp(restA->name,restB->name) == 0){
		return(0);
	}else if(strcmp(restA->name,restB->name) < 0){
		return(1);
	}else{
		printf("\nError comparing names");
	}
	return(0);	
}
int compareRating (void const * first, void const * second){
	Restaurant * restA;
	Restaurant * restB;
	
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
	return(0);	
}

void printRestaurant(void * input){
	
}