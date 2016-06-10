#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Element * createList(void * structPtr, int ptrSize){
	Element * list;
	int test;
	
	test = sizeof(structPtr);
	
	printf("\nList step two");
	getchar();
	list = malloc(sizeof(Element));
	printf("\nList step three");
	getchar();
	memcpy(list->structPtr,structPtr,test);
	printf("\nList step four");
	getchar();
	list->ptrSize = ptrSize;
	printf("\nList step five");
	getchar();
	list->next = NULL;
	printf("\nList step six");
	getchar();
	
	return(list);
}
Element * addToFront(void * structPtr,Element * list, int ptrSize){
	Element * element;
	printf("\nList step one");
	getchar();
	element = createList(structPtr, ptrSize);
	printf("\nList step seven");
	getchar();
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
	}
	
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
		memcpy(ptr,list->structPtr,list->ptrSize);
		tempElement = tempElement->next;
	}
	return (ptr);
}