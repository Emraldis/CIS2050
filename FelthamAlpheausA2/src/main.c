#include <stdio.h>
#include <string.h>
#include "hashADT.h"
#include "directory.h"
#include "list.h"

int main(int argc, char * argv[]){
	FILE * dirFile;
	char * fileName;
	Element * nameList;
	DirEntry * tempDir;
	Element * hashTable;
	HashEntry * tempHash;
	Element * tempElement;
	int hashSize;
	int dirSize;
	double tempDouble;
	char menu = ' ';
	char * searchKey;
	int tempKey;
	
	fileName = malloc(sizeof(char) * 256);
	tempDir = malloc(sizeof(DirEntry));
	tempElement = malloc(sizeof(Element));
	searchKey = malloc(sizeof(char) * 256);
	nameList = malloc(sizeof(Element));
	
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
	nameList = NULL;
	nameList = addToNameList(dirFile,nameList);
	
	fclose(dirFile);
	
	dirSize = getSize(nameList);
	
	printf("\n\nList is %d entries large\n",dirSize);
	tempElement = nameList;
	hashTable = NULL;
	while(tempElement != NULL){
		memcpy(tempDir,tempElement->structPtr,(sizeof(DirEntry)));
		printDir(tempDir);
		tempDouble = tempDir->phoneNum;
		printf("\nGenerating a key from %.0f",tempDouble);
		tempHash = createHashEntry(tempDouble,tempDir,hashTable,dirSize,sizeof(DirEntry));
		if(hashTable == NULL){
			printf("\nCreating new hash");
			hashTable = createList(tempHash,sizeof(HashEntry));
			hashTable->next = NULL;
			if(tempHash == NULL){
				printf("\nERROR\n");
				exit(0);
			}
		}else{
			if(tempHash != NULL){
				printf("\nCreating new hash");
				hashTable = addToFront(tempHash,hashTable,sizeof(HashEntry));
			}
		}
		tempElement = tempElement->next;
	}
	printf("\nHash Table completed, verifying");
	hashSize = getSize(hashTable);
	printf("\nHash Table is %d entries large", hashSize);
	tempElement = hashTable;
	
	while(tempElement != NULL){
		if(tempElement != NULL){
			tempHash = tempElement->structPtr;
			printTableEntry(tempHash);
			if(tempElement->next){
				tempElement = tempElement->next;
			}else{
				break;
			}
		}else{
			printf("\nERROR");
		}
	}
	
	printf("\n\fFinished setting up Phone Directory");
	
	while(menu != 'q'){
		printf("\n1)Search by Phone number\n2) Add a Phone Number 3)Import Numbers from a File\n");
		fgets(searchKey,256,stdin);
		if((searchKey[0] == 'q') || (searchKey[0] == 'Q')){
			menu = 'q';
			printf("\nQuitting");
			break;
		}
		printf("\n%s",searchKey);
		tempDouble = atof(searchKey);
		tempKey = newHashKey(tempDouble,dirSize);
		tempHash = keyExists(tempKey,hashTable);
		if(tempHash == NULL){
			printf("\nThat Phone Number does not exist");
		}else{
			printf("\nSearching through similar phone numbers");
			tempElement = tempHash->subList;
			tempDir = tempElement->structPtr;
			if(tempDir->phoneNum == tempDouble){
				printf("\nFound something:");
				printDir(tempDir);
			}
			while((tempElement != NULL) && (tempDir->phoneNum != tempDouble)){
				tempDir = tempElement->structPtr;
				if(tempDir->phoneNum == tempDouble){
					printf("\nFound something:");
					printDir(tempDir);
				}else{
					tempElement = tempElement->next;
				}
				if(tempElement == NULL){
					printf("\nThat Phone Number does not exist");
				}
			}
		}
		getchar();
		printf("\f");
	}
	printf("\n");
	return(0);
}