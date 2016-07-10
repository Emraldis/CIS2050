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
	int hashSize;
	
	fileName = malloc(sizeof(char) * 256);
	strcpy(fileName,"PhoneNumbers.txt");
	nameList = malloc(sizeof(Element));
	tempElement = malloc(sizeof(Element));
	tempDir = malloc(sizeof(DirEntry));
	tempHash = malloc(sizeof(HashEntry));
	hashTable = malloc(sizeof(Element));
	
	testFile = fopen(fileName,"r");
	
	if(testFile == NULL){
		printf("\nError Opening Test File");
		exit(0);
	}
	
	nameList = NULL;
	nameList = addToNameList(testFile,nameList);
	
	fclose(testFile);
	
	dirSize = getSize(nameList);
	
	printf("\nCreated Namelist (size %d), converting to hash table", dirSize);
	getchar();
	
	tempElement = nameList;
	
	while(tempElement != NULL){
		tempDir = tempElement->structPtr;
		printDir(tempDir);
		printf("\nTESTA");
		getchar();
		hashTable = addToHashTable(hashTable,tempDir,dirSize);
		printf("\nTESTB");
		getchar();
		tempElement = tempElement->next;
	}
	
	tempElement = hashTable;
	
	hashSize = getSize(hashTable);
	
	printf("\nFinished Creating Hash Table. Hash Table is %d entries large", hashSize);
	getchar();
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