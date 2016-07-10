#include <stdio.h>
#include <stdlib.h>
#include "hashADT.h"
#include "directory.h"

int main (void){
	FILE * testFile;
	Element * hashTable;
	DirEntry * tempDir;
	HashEntry * tempHash;
	Element * tempElement;
	char * fileName;
	Element * nameList;
	int dirSize;
	
	fileName = malloc(sizeof(char) * 256);
	strcpy(fileName,"PhoneNumbers.txt");
	nameList = malloc(sizeof(Element));
	tempElement = malloc(sizeof(Element));
	tempDir = malloc(sizeof(DirEntry));
	tempHash = malloc(sizeof(HashEntry));
	
	testFile = fopen(fileName,"r");
	
	if(testFile == NULL){
		printf("\nError Opening Test File");
		exit(0);
	}
	
	nameList = NULL;
	nameList = addToNameList(testFile,nameList);
	
	fclose(testFile);
	
	dirSize = getSize(nameList);
	
	tempElement = nameList;
	
	while(tempElement != NULL){
		memcpy(tempDir,tempElement->structPtr,sizeof(DirEntry));
		tempDouble = tempDir->phoneNum;
		hashTable = addToHashTable(hashTable,TempDir,dirSize);
		tempElement = tempElement->next;
	}
	
	tempElement = hashTable;
	
	printf("\nFinished Creating Hash Table. Hash Table is %d entries large", hashSize);
	while(tempElement != NULL){
		tempHash = tempElement->structPtr;
		printTableEntry(tempHash);
		tempElement = tempElement->next;
	}
	printf("\nDeleting A Hash Entry");
	hashTable->structPtr = deleteHash(hashTable->structPtr);
	
	while(tempElement != NULL){
		tempHash = tempElement->structPtr;
		printTableEntry(tempHash);
		tempElement = tempElement->next;
	}
	printf("\nAttempting to delete an empty Hash Entry");
	hashTable->structPtr = deleteHash(hashTable->structPtr);
	
	while(tempElement != NULL){
		tempHash = tempElement->structPtr;
		printTableEntry(tempHash);
		tempElement = tempElement->next;
	}
	printf("\nAttempting to query the size of the Hash Entry's Sublist");
	printf("\nSublist Size:%d",subListSize(hashTable->structPtr));
	
	printf("\nIf nothing has segfaulted by now, the ADT should be stable");
	return(0);
}