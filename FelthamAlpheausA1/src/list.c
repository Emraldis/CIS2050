#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Element * createList(void * structPtr){
	Element * list;
	
	list = malloc(sizeof(Element));
	list->&structPtr = &structPtr;
	list->next = NULL;
	
	return(list);
}
Element * addToFront(void * structPtr,Element * list){
	Element * element;
	
	element = createList(structPtr);
	element->next = list;
	
	return(element);
}
Element * addToBack(void * structPtr,Element * list){
	Element * currentPos;
	Element * element;
	currentPos = list;
	element = createList(structPtr);
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
	&ptr = list->&structPtr;
	return (ptr);
}
void * getValueBack(Element * list){
	void * ptr;
	Element * tempElement;
	tempElement = list;
	while(tempElement != NULL){
		&ptr = tempElement->&structPtr;
		tempElement = tempElement->next;
	}
	return (ptr);
}