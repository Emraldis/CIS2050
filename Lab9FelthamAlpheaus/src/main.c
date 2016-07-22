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
	int i;
	
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
	getchar();
	i =0;
	while(fgets(tempString,128,dataFile) != NULL){
		i++;
		printf("\nStarting");
		getchar();
		tempResName = strtok(tempString,",");
		printf("\n1");
		getchar();
		tempFoodType = strtok(NULL,",");
		printf("\n2");
		getchar();
		tempIntString = strtok(NULL,"\n");
		printf("\n3");
		getchar();
		tempInt = atoi(tempIntString);
		printf("\n4");
		getchar();
		tempRestaurant = createRestaurant(tempInt,tempResName,tempFoodType);
		printf("\n5");
		getchar();
		tempBranch = createBranch(tempRestaurant);
		printf("\n6");
		getchar();
		treeName = addBranch(treeName,tempBranch,compareName);
		printf("\n7");
		getchar();
		treeRating = addBranch(treeRating,tempBranch,compareRating);
		printf("\n8");
		getchar();
		printf("\n%d",i);
		getchar();
	}
	printf("\nTrees complete");
	
	return(0);
}