#include "directory.h"

DirEntry * newEntry(char * input){
	DirEntry * newDir;
	char * tempString;
	
	printf("\nCreating new Entry with: %s",input);
	
	newDir = malloc(sizeof(DirEntry));
	newDir->firstName = malloc(sizeof(char) * 32);
	newDir->lastName = malloc(sizeof(char) * 32);
	tempString = malloc(sizeof(char) * 32);
	
	tempString = strtok(input,",");
	strcpy(newDir->firstName,tempString);
	tempString = strtok(NULL,",");
	strcpy(newDir->lastName,tempString);
	tempString = strtok(NULL,"\n");
	newDir->phoneNum = decode(tempString);
	
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
		if(tempElement != NULL){
			tempDir = tempElement->structPtr;
			printDir(tempDir);
			tempElement = tempElement->next;
		}
	}
	
}

void printDir(DirEntry * directory){
	if((directory == NULL)||(directory->firstName == NULL)||(directory->lastName == NULL)){
		printf("\nDATA MISSING");
	}else{
		printf("\n\tFirstName: %s\n\tLastName: %s\n\tPhone Number: %.0f",directory->firstName,directory->lastName,directory->phoneNum);
	}
}

double decode(char * phoneNum){
	double output = 0;
	int i;
	int j = 0;
	
	for(i=(strlen(phoneNum));i>-1;i--){
		switch(phoneNum[j]){
			case '0':
				output = (output + 0);
				break;
			case '1':
				output = (output + (1 * pwr(10,i)));
				break;
			case '2':
				output = (output + (2 * pwr(10,i)));
				break;
			case '3':
				output = (output + (3 * pwr(10,i)));
				break;
			case '4':
				output = (output + (4 * pwr(10,i)));
				break;
			case '5':
				output = (output + (5 * pwr(10,i)));
				break;
			case '6':
				output = (output + (6 * pwr(10,i)));
				break;
			case '7':
				output = (output + (7 * pwr(10,i)));
				break;
			case '8':
				output = (output + (8 * pwr(10,i)));
				break;
			case '9':
				output = (output + (9 * pwr(10,i)));
				break;
			default:
			printf("\nERROR DECODING");
				exit(1);
		}
		printf("\nDECODED: %f",output);
		j++;
	}
	return(output);
}

double pwr(int base, int exponent){
	int i;
	double output = 0;
	
	output = base;
	if(exponent == 0){
		printf("\nExponent was 0");
		return(1);
	}else if(exponent == 1){
		return(base);
	}
	for(i=0;i<(exponent - 2);i++){
		output = (output * base);
	}

	
	return(output);
}

Element * addToNameList(FILE * inputFile, Element * nameList){
	DirEntry * tempDir;
	char * data;
	
	tempDir = malloc(sizeof(DirEntry));
	data = malloc(sizeof(char) * 256);
	
	while(fgets(data,256,inputFile) != NULL){
		tempDir = newEntry(data);
		nameList = addToFront(tempDir,nameList,sizeof(DirEntry));
		printDir(tempDir);
		printf("\nDirectory Added to list");
	}
	return(nameList);
}

Element * addToHashTable(Element * hashTable,DirEntry * entry, int dirSize){
	HashEntry * tempHash;
	
	tempHash = malloc(sizeof(HashEntry));
	
	tempHash = createHashEntry(entry->phoneNum,entry,hashTable,dirSize,sizeof(DirEntry));
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
	return(hashTable);
}