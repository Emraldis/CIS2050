#include "hastADT.h"

HashEntry * createHashEntry(int keyBase, void * element, Element * table, int dataSize){
	HashEntry * newHash;
	int key;
	
	newHash = malloc(sizeof(HashEntry));
	
	key = newHashKey(keyBase,dataSize);
	if(keyExists(key,table) != NULL){
		newHash = keyExists(key,table);
		newHash = addToSubList(newHash,element);
	}else{
		newHash->hashKey = key;
		newHash->subList = createList(element,sizeof(element));
	}
	return(newHash);
}

int newHashKey(int keyBase, int dataSize){
	int key;
	int tempIntA;
	int tempIntB;
	char * tempString;
	char * tempStringTwo;
	
	tempString = malloc(sizeof(char) * 16);
	tempStringTwo = malloc(sizeof(char) * 4);
	
	sprintf(tempString,"%d",(keyBase - 6045000000));
	strcpy(tempStringTwo,tempString[0]);
	strcat(tempStringTwo,tempString[1]);
	strcat(tempStringTwo,tempString[2]);
	tempIntA = atoi(tempStringTwo);
	strcpy(tempStringTwo,tempString[3]);
	strcat(tempStringTwo,tempString[4]);
	strcat(tempStringTwo,tempString[5]);
	tempIntB = atoi(tempStringTwo);
	
	key = ((tempIntA * tempIntB) % (dataSize * (2/3)));
	
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

HashEntry * addToSubList(HashEntry * entry, void * element){
	
	entry->subList = addToBack(element,entry->subList,sizeof(element));
	
	return(entry);
}

int subListSize(HashEntry * entry){
	int count;
	
	count = getSize(entry->subList);
	
	return(count);
}