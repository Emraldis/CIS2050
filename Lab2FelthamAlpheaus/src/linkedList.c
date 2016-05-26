#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
List * createList(char * value){
	List * list;
	
	list = malloc(sizeof(List));
	list->next = NULL;
	list->value = value;
	
	return(list);
}

/*Destroys a list
precondition: none
postcondition: Must return an empty pointer
*/
List * destroyList(){
	return(NULL);
}

/*Adds List element to the front of a pre-existing list
precondition: list must exist (if element is NULL it won't do anything to the list->next pointer anyway)
postcondition: Must have properly added the element to the front of the list, and then return the list head
*/
List * addToFront(List * element, List * list){
	element->next = list->next;
	list->next = element;
	return(list);
}

/*Returns the value of the first element in the list
precondition: List must not be empty
postcondition: Must return the correct value
*/
char * readFirstValue(List * list){
	if(list != NULL){
		return(list->value);
	}
	
	return(NULL);
}

/*Returns the length of the list
precondition: list must exist, though if the list is NULL, it will simply return a length of 0
postcondition: Must return the correct length of the list.
*/
int getLength(List * list){
	int i = 0;
	List * currentPos = list;
	
	if(currentPos != NULL){
		while(currentPos->next != NULL){
			i++;
			currentPos = currentPos->next;
		}
	}
	
	return(i);
}

/*Prints the values of each element in the list
precondition: List shouldn't be empty, but will return error message if it is
postcondition: Must properly print the list values
*/
void printList(List * list){
	List * currentPos = list;
	if(currentPos == NULL){
		printf("\n Empty List");
		return();
	}
	if(currentPos->next != NULL){
		while(currentPos->next != NULL){
			printf("\n%s",list->value);
		}
	}
}

/*Removes the frist element of the list
precondition: List should exist, but if it does not, will simply return the non-existent list, I.E. NULL
postcondition: Must properly remove the front value
*/
List * removeFromFront(List * list){

	if(list != NULL){
		if(list->next != NULL){
			return(list->next);
		}else{
			return(NULL);
		}
	}
	return(list);
}