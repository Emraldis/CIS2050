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
	char * firstName;
	char * lastName;
	char * tempString;
	
	fileName = malloc(sizeof(char) * 256);
	tempDir = malloc(sizeof(DirEntry));
	tempElement = malloc(sizeof(Element));
	searchKey = malloc(sizeof(char) * 256);
	nameList = malloc(sizeof(Element));
	firstName = malloc(sizeof(char) * 128);
	lastName = malloc(sizeof(char) * 128);
	tempString = malloc(sizeof(char) * 16);
	
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
	hashTable = NULL;
	tempElement = nameList;
	while(tempElement != NULL){
		memcpy(tempDir,tempElement->structPtr,(sizeof(DirEntry)));
		printDir(tempDir);
		tempDouble = tempDir->phoneNum;
		printf("\nGenerating a key from %.0f",tempDouble);
		hashTable = addToHashTable(hashTable,tempDir,dirSize);
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
			tempElement = tempElement->next;
		}else{
			printf("\nERROR");
		}
	}
	
	printf("\n\fFinished setting up Phone Directory");
	
	while(menu != 'q'){
		printf("\n1)Search by Phone number\n2) Add a Phone Number \n3)Import Numbers from a File\n4)Print Directory\nEnter 'q' to quit.\n");
		menu = getchar();
		getchar();
		if((menu == 'q') || (menu == 'Q')){
			menu = 'q';
			printf("\nQuitting\n");
			exit(0);
		}
		switch(menu){
			case'1':
				printf("\nPlease enter the phone number for which you wish to search:\n");
				fgets(searchKey,256,stdin);
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
				break;
			case'2':
				printf("\nPlease Enter a First Name:\n");
				fgets(firstName,128,stdin);
				getchar();
				firstName = strtok(firstName,"\n");
				printf("\nPlease Enter a Last Name:\n");
				fgets(lastName,128,stdin);
				getchar();
				lastName = strtok(lastName,"\n");
				printf("\nPlease Enter a Phone Number:\n");
				fgets(tempString,10,stdin);
				getchar();
				tempString = strtok(tempString,"\n");
				strcat(searchKey,firstName);
				strcat(searchKey,",");
				strcat(searchKey,lastName);
				strcat(searchKey,",");
				strcat(searchKey,tempString);
				strcat(searchKey,"\n");
				tempDir = newEntry(searchKey);
				nameList = addToFront(tempDir,nameList,sizeof(DirEntry));
				hashTable = addToHashTable(hashTable,tempDir,dirSize);
				break;
			case'3':
				printf("\nPlease enter the file name:\n");
				fgets(fileName,256,stdin);
				dirFile = fopen(fileName,"r");
				nameList = addToNameList(dirFile,nameList);
				tempElement = hashTable;
				while(tempElement != NULL){
					tempElement->structPtr = deleteHash(tempElement->structPtr);
					tempElement = tempElement->next;
				}
				hashTable = deleteList(hashTable);
				tempElement = nameList;
				while(tempElement != NULL){
					memcpy(tempDir,tempElement->structPtr,(sizeof(DirEntry)));
					printDir(tempDir);
					tempDouble = tempDir->phoneNum;
					printf("\nGenerating a key from %.0f",tempDouble);
					hashTable = addToHashTable(hashTable,tempDir,dirSize);
					tempElement = tempElement->next;
				}
				break;
			case'4':
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
				break;
			default:
				printf("\nInput not recognized, please try again");
				break;
		}
		getchar();
		printf("\f");
	}
	printf("\n");
	return(0);
}