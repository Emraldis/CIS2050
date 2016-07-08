#include <stdio.h>
#include <string.h>
#include "hashADT.h"
#include "directory.h"

int main(int argc, char * argv[]){
	FILE * dirFile;
	char * fileName;
	Element * nameList;
	char * data;
	dirEntry * tempDir;
	Element * hashTable;
	hashEntry * tempHash;
	Element * tempElement;
	int dirSize;
	
	fileName = malloc(sizeof(char) * 256);
	data = malloc(sizeof(char) * 256);
	tempDir = malloc(sizeof(dirEntry));
	tempElement = malloc(sizeof(Element));
	
	if(argc != 1){
		strcpy(fileName,argv[1]);
	}else{
		strcpy(fileName,"PhoneNumbers.txt");
	}
	dirFile = fopen(fileName,"r");
	
	if(dirFile == NULL){
		printf("\nError opening file);
		exit(0);
	}
	
	while(fgets(data,256,dirFile) != NULL){
		tempDir = newEntry(data);
		nameList = addToFront(tempDir,nameList,sizeof(tempDir));
	}
	fclose(dirFile);
	
	dirSize = getSize(nameList);
	tempElement = nameList;
	while(tempElement != NULL){
		tempDir = tempElement->structPtr;
		tempHash = createHashEntry(tempDir,hashTable,dirSize);
		hashTable = addToFront(tempHash,hashTable,sizeof(tempHash));
	}
	
	return(0);
}