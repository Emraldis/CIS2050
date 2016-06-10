#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "testData.h"
#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

int main(void){
	int i;
	char * string;
	Test * data;
	Element * list;
	void * dataPtr;
	Element * currentPos;
	Stack * stack;
	Stack * tempStack;
	
	string = malloc(sizeof(char) * 128);
	list = NULL;
	dataPtr = NULL;
	
	printf("\n********************************Testing List ADT********************************");
	//getchar();
	printf("\nCreating List");
	for(i=1;i<101;i++){
		sprintf(string,"%d",i);
		data = create(string);
		list = addToFront(data,list,sizeof(data));
	}
	//getchar();
	printf("\nPrinting List:");
	currentPos = list;
	while(currentPos != NULL){
		printData(currentPos->structPtr);
		currentPos = currentPos->next;
	}
	printf("\nFirst value is:");
	printData(getValueFront(list));
	printf("\nLast value is:");
	printData(getValueBack(list));
	printf("\nTesting remove from front:");
	list = removeFromFront(list);
	printf("\nFirst value is:");
	printData(getValueFront(list));
	printf("\nTesting remove from back:");
	list = removeFromBack(list);
	printf("\nLast value is:");
	printData(getValueBack(list));
	printf("\nPrinting List:");
	currentPos = list;
	while(currentPos != NULL){
		printData(currentPos->structPtr);
		currentPos = currentPos->next;
	}
	printf("\nDeleting list");
	list = deleteList(list);
	printf("\nFirst value is:");
	printData(getValueFront(list));
	printf("\nLast value is:");
	printData(getValueBack(list));
	printf("\nPrinting List:");
	currentPos = list;
	while(currentPos != NULL){
		printData(currentPos->structPtr);
		currentPos = currentPos->next;
	}
	printf("\nTesting remove from front:");
	list = removeFromFront(list);
	printf("\nTesting remove from back:");
	list = removeFromBack(list);
	printf("\nTesting add to back");
	for(i=1;i<101;i++){
		sprintf(string,"%d",i);
		data = create(string);
		list = addToBack(data,list,sizeof(data));
	}
	printf("\nPrinting List:");
	currentPos = list;
	while(currentPos != NULL){
		printData(currentPos->structPtr);
		currentPos = currentPos->next;
	}
	printf("\nFirst value is:");
	printData(getValueFront(list));
	printf("\nLast value is:");
	printData(getValueBack(list));
	printf("\nIf no segfaults occured, then the list test was successful, deleting list.\n");
	list = deleteList(list);
	printf("\n********************************Testing Stack ADT********************************");
	printf("\nCreating stack:");
	for(i=1;i<101;i++){
		sprintf(string,"%d",i);
		data = create(string);
		stack = addToStack(data, stack, sizeof(data));
	}
	printf("\nPrinting Stack");
	tempStack = stack;
	while(tempStack != NULL){
		printData(tempStack->structPtr);
		tempStack = tempStack->under;
	}
	
	return(0);
}