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
	int hashSize;
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
		printDir(tempDir);
		printf("\nDirectory Added to list");
	}
	fclose(dirFile);
	
	dirSize = getSize(nameList);
	
	printf("\n\nList is %d entries large\n",dirSize);
	tempElement = nameList;
	hashTable = NULL;
	while(tempElement != NULL){
		memcpy(tempDir,tempElement->structPtr,(sizeof(DirEntry)));
		printDir(tempDir);
		tempDouble = tempDir->phoneNum;
		printf("\nGenerating a key from %f",tempDouble);
		tempHash = createHashEntry(tempDouble,tempDir,hashTable,dirSize,sizeof(DirEntry));
		if(tempHash != NULL){
			hashTable = addToFront(tempHash,hashTable,sizeof(HashEntry));
		}
		tempElement = tempElement->next;
	}
	printf("\nHash Table completed, verifying");
	getchar();
	hashSize = getSize(hashTable);
	printf("\nHash Table is %d entries large", hashSize);
	tempElement = hashTable;
	
	while(tempElement != NULL){
		if(tempElement != NULL){
			tempHash = tempElement->structPtr;
			printTableEntry(tempHash);
			tempElement = tempElement->next;
		}else{
			printf("\nERROR");
		}
	}
	return(0);
}