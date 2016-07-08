#include "hashADT.h"

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
	int tempInt;
	char * tempString;
	char * intStorage;
	int i;
	
	printf("\nCreating Hash key");
	getchar();
	tempString = malloc(sizeof(char) * 16);
	intStorage = malloc(sizeof(char) * 2);
	tempInt = 0;
	sprintf(tempString,"%d",keyBase);
	for(i=0;i<(strlen(tempString));i++){
		intStorage[0] = tempString[i];
		tempInt = (tempInt * (1 + (atoi(intStorage))));
	}
	printf("\n%d",(tempInt));
	getchar();
	key = ((tempInt) % (dataSize * (2/3)));
	
	printf("\nKey generatred: %d",key);
	getchar();
	
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