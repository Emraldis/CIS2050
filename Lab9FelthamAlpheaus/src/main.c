#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binTree.h"
#include "data.h"

int main(void){
	FILE * dataFile;
	char * tempResName;
	char * tempFoodType;
	char * tempIntString;
	char * tempString;
	int tempInt;
	Restaurant * tempRestaurant;
	Branch * treeName;
	Branch * treeRating;
	Branch * tempBranch;
	
	tempResName = malloc(sizeof(char) * 64);
	tempFoodType = malloc(sizeof(char) * 64);
	tempIntString = malloc(sizeof(char) * 4);
	tempString = malloc(sizeof(char) * 128);
	tempRestaurant = malloc(sizeof(Restaurant));
	treeName = malloc(sizeof(Branch));
	treeRating = malloc(sizeof(Branch));
	tempBranch = malloc(sizeof(Branch));
	
	dataFile = fopen("Restaurants.txt","r");
	
	if(dataFile == NULL){
		printf("\nError opening data file");
		exit(0);
	}
	
	while(fgets(tempString,128,dataFile) != NULL){
		tempResName = strtok(tempString,",");
		tempFoodType = strtok(NULL,",");
		tempIntString = strtok(NULL,"\n");
		tempInt = atoi(tempIntString);
		tempRestaurant = createRestaurant(tempInt,tempResName,tempFoodType);
		tempBranch = createBranch(tempRestaurant);
		treeName = addBranch(treeName,tempBranch,compareName);
		treeRating = addBranch(treeRating,tempBranch,compareRating);
		
	}
	printf("\nTrees complete");
	
	return(0);
}