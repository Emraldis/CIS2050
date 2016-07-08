#include "directory.h"

DirEntry * newEntry(char * input){
	DirEntry * newDir;
	
	printf("\nCreating new Entry with: %s",input);
	
	newDir = malloc(sizeof(DirEntry));
	newDir->firstName = malloc(sizeof(char) * 32);
	newDir->lastName = malloc(sizeof(char) * 32);
	
	strcpy(newDir->firstName,strtok(input,","));
	strcpy(newDir->lastName,strtok(NULL,","));
	newDir->phoneNum = atoi(strtok(NULL,"\n"));
	
	printf("\nNew Directory entry created:\nFirstName: %s\nLastName: %s\nPhone Number: %d",newDir->firstName,newDir->lastName,newDir->phoneNum);
	
	return(newDir);
}

void printTableEntry(HashEntry * entry){
	Element * tempElement;
	DirEntry * tempDir;
	
	tempElement = malloc(sizeof(Element));
	tempDir = malloc(sizeof(DirEntry));
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

void printDir(DirEntry * directory){
	if(directory == NULL){
		printf("\nEMPTY DIRECTORY");
	}else{
		printf("\n\tFirstName: %s\n\tLastName: %s\n\tPhone Number: %d",directory->firstName,directory->lastName,directory->phoneNum);
	}
}