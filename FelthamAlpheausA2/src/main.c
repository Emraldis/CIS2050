#include <stdio.h>
#include <string.h>
#include "hashADT.h"
#include "directory.h"
#include "list.h"

int main(int argc, char * argv[]){
	FILE * dirFile;
	char * fileName;
	Element * nameList;
	char * data;
	DirEntry * tempDir;
	Element * hashTable;
	HashEntry * tempHash;
	Element * tempElement;
	int dirSize;
	double tempDouble;
	int tempInt;
	
	fileName = malloc(sizeof(char) * 256);
	data = malloc(sizeof(char) * 256);
	tempDir = malloc(sizeof(DirEntry));
	tempElement = malloc(sizeof(Element));
	
	if(argc != 1){
		strcpy(fileName,argv[1]);
	}else{
		strcpy(fileName,"PhoneNumbers.txt");
	}
	dirFile = fopen(fileName,"r");
	
	if(dirFile == NULL){
		printf("\nError opening file");
		exit(0);
	}
	
	while(fgets(data,256,dirFile) != NULL){
		tempDir = newEntry(data);
		nameList = addToFront(tempDir,nameList,sizeof(tempDir));
		printf("\nDirectory Added to list");
	}
	fclose(dirFile);
	
	dirSize = getSize(nameList);
	
	printf("\n\nList is %d entries large\n",dirSize);
	
	tempElement = nameList;
	hashTable = NULL;
	while(tempElement != NULL){
		memcpy(tempDir,tempElement->structPtr,tempElement->ptrSize);
		tempDouble = (tempDir->phoneNum - 6045000000);
		tempInt = (tempDouble * 1);
		printf("\nGenerating a key from %d",tempInt);
		tempHash = createHashEntry(tempInt,tempDir,hashTable,dirSize);
		hashTable = addToFront(tempHash,hashTable,sizeof(tempHash));
		tempElement = tempElement->next;
	}
	printf("\nHash Table completed, verifying");
	getchar();
	tempElement = hashTable;
	
	while(tempElement != NULL){
		printf("\nTEST A");
		getchar();
		/*
		tempHash = tempElement->structPtr;
		printf("\nTEST B");
		getchar();
		printf("\nFor key: %d, there are %d entries",tempHash->hashKey,subListSize(tempHash));
		printf("\nTEST C");
		getchar();
		*/
		tempElement = tempElement->next;
		printf("\nTEST D");
		getchar();
	}
	return(0);
}