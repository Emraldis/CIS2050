#include "data.h"

/*Alpheaus Feltham, 0903594*/

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
	strcpy(newRest->name,name);
	strcpy(newRest->foodType,foodType);
	
	return(newRest);
}

void deleteRestaurant (void const * input){
	Restaurant * toDelete;
	
	toDelete = input;
	
	if(toDelete != NULL){
		toDelete->name = NULL;
		toDelete->foodType = NULL;
		
		free(toDelete->name);
		free(toDelete->foodType);
		free(toDelete);
	}else{
		//printf("\nNothing to delete");
	}
}

int compareName (void const * first, void const * second){
	Restaurant * restA;
	Restaurant * restB;
	char * testA;
	char * testB;
	
	restA = malloc(sizeof(Restaurant));
	restB = malloc(sizeof(Restaurant));
	testA = malloc(sizeof(char ) * 128);
	testB = malloc(sizeof(char ) * 128);
	
	memcpy(restA,first,sizeof(Restaurant));
	memcpy(restB,second,sizeof(Restaurant));
	strcpy(testA,restA->name);
	strcpy(testB,restB->name);
	strcat(testA,restA->foodType);
	strcat(testB,restB->foodType);
	printf("\n%s =?= %s",testA,testB);
	if(strcmp(testA,testB) > 0){
		return(-1);
	}else if(strcmp(testA,testB) == 0){
		return(0);
	}else if(strcmp(testA,testB) < 0){
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
	
	//printf("\nTEST A: %d",restA->rating);
	//printf("\nTEST B: %d",restB->rating);
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

void printRestaurant(void const * input){
	Restaurant * toPrint;
	
	toPrint = malloc(sizeof(Restaurant));
	
	if(input == NULL){
		printf("EMPTY");
	}else{
		memcpy(toPrint,input,sizeof(Restaurant));
		printf("%s,%s (Rating: %d)",toPrint->name,toPrint->foodType,toPrint->rating);
	}
}