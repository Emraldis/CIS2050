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
	treeName = NULL;
	while(fgets(tempString,128,dataFile) != NULL){
		printf("\nStarting");
		tempResName = strtok(tempString,",");
		tempFoodType = strtok(NULL,",");
		tempIntString = strtok(NULL,"\n");
		tempInt = atoi(tempIntString);
		tempRestaurant = createRestaurant(tempInt,tempResName,tempFoodType);
		tempBranch = createBranch(tempRestaurant);
		printf("\nAdding name Branch");
		treeName = addBranch(treeName,tempBranch,compareName);
	}
	fclose(dataFile);
	getchar();
	printf("\nTrees complete");
	printf("\nTraversing Tree");
	traverseTree(treeName,printRestaurant);
	getchar();
	printf("\nTraversing Complete");
	printf("\nDeleting Tree");
	deleteTree(treeName,deleteRestaurant);
	printf("\nDeleting Completed");
	
	
	dataFile = fopen("Restaurants.txt","r");
	
	if(dataFile == NULL){
		printf("\nError opening data file");
		exit(0);
	}
	treeRating = NULL;
	while(fgets(tempString,128,dataFile) != NULL){
		printf("\nStarting");
		tempResName = strtok(tempString,",");
		tempFoodType = strtok(NULL,",");
		tempIntString = strtok(NULL,"\n");
		tempInt = atoi(tempIntString);
		tempRestaurant = createRestaurant(tempInt,tempResName,tempFoodType);
		tempBranch = createBranch(tempRestaurant);printf("\nAdding rating Branch");
		treeRating = addBranch(treeRating,tempBranch,compareRating);
	}
	fclose(dataFile);
	getchar();
	printf("\nTrees complete");
	printf("\nTraversing Tree");
	traverseTree(treeRating,printRestaurant);
	getchar();
	printf("\nTraversing Complete");
	printf("\nDeleting Tree");
	deleteTree(treeRating,deleteRestaurant);
	printf("\nDeleting Completed");
	return(0);
}