#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "testData.h"
#include "stackADT.h"

int main(void){
	int i;
	char * string;
	Test * data;
	Element * list;
	void * dataPtr;
	Element * currentPos;
	
	string = malloc(sizeof(char) * 128);
	list = NULL;
	dataPtr = NULL;
	
	printf("/nTesting List ADT:");
	getchar();
	printf("/nCreating List");
	for(i=1;i<101;i++){
		sprintf(string,"%d",i);
		data = create(string);
		memcpy(dataPtr,data,sizeof(data));
		list = addToFront(dataPtr,list,sizeof(dataPtr));
	}
	getchar();
	printf("/nPrinting List:");
	currentPos = list;
	while(currentPos != NULL){
		printData(currentPos->structPtr);
	}
	
	return(0);
}