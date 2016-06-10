#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Element * createList(void * structPtr, int ptrSize){
	Element * list;
	int test;
	
	test = sizeof(structPtr);
	list = malloc(sizeof(Element));
	list->structPtr = malloc(ptrSize);
	memcpy(list->structPtr,structPtr,ptrSize);
	list->ptrSize = ptrSize;
	list->next = NULL;
	
	return(list);
}
Element * addToFront(void * structPtr,Element * list, int ptrSize){
	Element * element;
	element = createList(structPtr, ptrSize);
	element->next = list;
	
	return(element);
}
Element * addToBack(void * structPtr,Element * list, int ptrSize){
	Element * currentPos;
	Element * element;
	currentPos = list;
	element = createList(structPtr, ptrSize);
	if(list != NULL){
		while(currentPos->next != NULL){
			currentPos = currentPos->next;
		}
		currentPos->next = element;
	}else{
		list = element;
	}
	return (list);
}
Element * removeFromFront(Element * list){
	Element * tempElement;
	tempElement = list;
	list = list->next;
	free(tempElement->structPtr);
	free(tempElement);
	return (list);
}
Element * removeFromBack(Element * list){
	Element * currentPos;
	Element * tempElement;
	currentPos = list;
	if(currentPos->next != NULL){
		while(currentPos->next->next != NULL){
			currentPos = currentPos->next;
		}
	}else{
		return(NULL);
	}
	tempElement = currentPos->next;
	currentPos->next = NULL;
	free(tempElement);
	
	return (list);
}
void deleteList(Element * list){
	Element * tempElement;
	
	while (list != NULL){
		tempElement = list;
		list = list->next;
		free(tempElement->structPtr);
		free(tempElement);
		tempElement = NULL;
	}
	list = NULL;
	
}
void * getValueFront(Element * list){
	void * ptr;
	ptr = malloc(list->ptrSize);
	memcpy(ptr,list->structPtr,list->ptrSize);
	return (ptr);
}
void * getValueBack(Element * list){
	void * ptr;
	ptr = malloc(list->ptrSize);
	Element * tempElement;
	tempElement = list;
	while(tempElement != NULL){
		memcpy(ptr,tempElement->structPtr,tempElement->ptrSize);
		tempElement = tempElement->next;
	}
	return (ptr);
}