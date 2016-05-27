#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main (void){
	
	List * list;
	char * tempString;
	int i;
	
	tempString = malloc(sizeof(char) * 128);
	list = createList("Element Number 1");
	for(i=100;i>1;i--){
	    sprintf(tempString,"Element Number %d",i);
	    addToFront(createList(tempString),list);
	}
	printf("\nThe first element value is: %s",readFirstValue(list));
	getchar();
	printf("\nPrinting the list, it is %d elements large:",getLength(list));
	getchar();
	printList(list);
	getchar();
	printf("\nRemoving the first Element from the list;");
	list = removeFromFront(list);
	printf("\nThe first element value is now: %s",readFirstValue(list));
	printf("\nPrinting the list again, it is now %d elements large:",getLength(list));
	printList(list);
	printf("\nDeleting the list");
	list = destroyList(list);
	printf("\nThe first element is now: %s",readFirstValue(list));
	printf("\nPrinting the list again, it is now %d elements large:",getLength(list));
	printList(list);
	printf("\nNow attempting to remove the first value");
	list = removeFromFront(list);
	printf("\nThe first element value is now: %s",readFirstValue(list));
	printf("\nPrinting the list again, it is now %d elements large:",getLength(list));
	printList(list);
	printf("\nNow attempting to add an element to an empty list");
	list = addToFront(createList("Element Number 0"),list);
	printf("\nThe first element value is now: %s",readFirstValue(list));
	printf("\nPrinting the list again, it is now %d elements large:",getLength(list));
	printList(list);

	return(0);
}