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
		nameList = addToFront(tempDir,nameList,sizeof(DirEntry));
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
	printf("\nDone Creating Hash Table");
	getchar();
	tempElement = nameList;
	while(tempElement != NULL){
		tempHash = tempElement->structPtr;
		printf("\nSublist size for key %d is :%d",tempHash->hashKey,subListSize(tempHash));
		tempElement = tempElement->next;
	}
	return(0);
}