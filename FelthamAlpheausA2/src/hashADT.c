#include "hashADT.h"

HashEntry * createHashEntry(int keyBase, void * element, Element * table, int tableSize, int dataSize){
	HashEntry * newHash;
	int key;
	
	newHash = malloc(sizeof(HashEntry));
	
	key = newHashKey(keyBase,tableSize);
	if(table == NULL){
		newHash->hashKey = key;
		return(newHash);
	}
	if(keyExists(key,table) != NULL){
		newHash = keyExists(key,table);
		newHash->subList = addToFront(element,newHash->subList,dataSize);
		return(NULL);
	}else{
		newHash->hashKey = key;
		newHash->subList = createList(element,dataSize);
	}
	return(newHash);
}

int newHashKey(double keyBase, int tableSize){
	int key;
	int tempInt;
	char * tempString;
	int a = 0;
	int i;
	
	printf("\nCreating Hash key");
	tempString = malloc(sizeof(char) * 16);
	tempInt = 0;
	sprintf(tempString,"%.0f",keyBase);
	for(i=0;i<(strlen(tempString));i++){
		switch(tempString[i]){
			case'0':
				a = 0;
				break;
			case'1':
				a = 1;
				break;
			case'2':
				a = 2;
				break;
			case'3':
				a = 3;
				break;
			case'4':
				a = 4;
				break;
			case'5':
				a = 5;
				break;
			case'6':
				a = 6;
				break;
			case'7':
				a = 7;
				break;
			case'8':
				a = 8;
				break;
			case'9':
				a = 9;
				break;
			default:
				key = ((tempInt) % (tableSize / 2));
				printf("\nKey generatred: %d",key);
				return(key);
				
		}
		if(tempInt == 0){
			tempInt = a;
		}else{
			printf("\nMATH: %d * (1 + %d)",tempInt,a);
			tempInt = (tempInt * (1 + a));
			printf("\nSTEP %d",tempInt);
		}
	}
	key = ((tempInt) % (tableSize / 2));
	
	printf("\nKey generatred: %d",key);
	
	return(key);
}

HashEntry * keyExists(int key, Element * table){
	Element * currentLoc;
	HashEntry * tempEntry;
	
	tempEntry = malloc(sizeof(HashEntry));
	currentLoc = malloc(sizeof(Element));
	
	currentLoc = table;
	if(currentLoc != NULL){
		while(currentLoc != NULL){
			tempEntry = currentLoc->structPtr;
			if(tempEntry->hashKey == key){
				return(tempEntry);
			}
			currentLoc = currentLoc->next;
		}
	}
	
	return(NULL);
}

int subListSize(HashEntry * entry){
	int count;
	
	count = getSize(entry->subList);
	
	return(count);
}