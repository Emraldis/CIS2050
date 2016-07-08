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
	int tempIntA;
	int tempIntB;
	char * tempString;
	char * tempStringTwo;
	
	printf("\nCreating Hash key");
	getchar();
	tempString = malloc(sizeof(char) * 16);
	tempStringTwo = malloc(sizeof(char) * 4);
	tempIntA = (keyBase - 6045000000);
	sprintf(tempString,"%d",tempIntA);
	tempStringTwo[0] = tempString[0];
	tempStringTwo[1] = tempString[1];
	tempStringTwo[2] = tempString[2];
	tempIntA = atoi(tempStringTwo);
	tempStringTwo[0] = tempString[3];
	tempStringTwo[1] = tempString[4];
	tempStringTwo[2] = tempString[5];
	tempIntB = atoi(tempStringTwo);
	
	printf("\n%d"(tempIntA * tempIntB));
	getchar();
	key = ((tempIntA * tempIntB) % (dataSize * (2/3)));
	
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