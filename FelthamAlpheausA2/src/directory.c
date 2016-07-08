#include "directory.h"

dirEntry * newEntry(char * input){
	dierEntry * newDir;
	char * tempString = malloc(sizeof(char) * 128);
	newDir->firstName = malloc(sizeof(char) * 32);
	newDir->lastName = malloc(sizeof(char) * 32);
	
	strcpy(newDir->firstName,strtok(input,","));
	strcpy(newDir->lastName,strtok(NULL,","));
	newDir->phoneNum = atoi(strtok(NULL,","));
	
	printf("\nNew Directory entry created:\nFirstName: %s\nLastName: %s\nPhone Number: %d",newDir->firstName,newDir->lastName,newDir->phoneNum);
	
	return(newDir);
}

void printTableEntry(HashEntry * entry){
	Element * tempElement;
	dirEntry * tempDir;
	
	tempElement = malloc(sizeof(Element));
	tempDir = malloc(sizeof(dirEntry));
	tempDir->firstName = malloc(sizeof(char) * 32);
	tempDir->lastName = malloc(sizeof(char) * 32);
	
	tempElement = entry->subList;
	
	printf("\nFor Hash Key %d:",entry->hashKey);
	
	while(tempElement != NULL){
		tempDir = tempElement->structPtr;
		printDir(tempDir);
		tempElement = tempElement->next;
	}
	
}

void printDir (dirEntry * directory){
	if(directory == NULL){
		printf("\nEMPTY DIRECTORY");
	}else{
		printf("\n\tFirstName: %s\n\tLastName: %s\n\tPhone Number: %d",directory->firstName,directory->lastName,directory->phoneNum);
	}
	return();
}