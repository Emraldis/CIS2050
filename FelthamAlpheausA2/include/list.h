#ifndef _AFELTHAM_HEADERH_LIST
#define _AFELTHAM_HEADERH_LIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Alpheaus Feltham, 0903594*/

typedef struct ListElement{
	void * structPtr;
	struct ListElement * next;
	int ptrSize;
}Element;
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
Element * createList(void * structPtr, int ptrSize);
/*Creates a new List element and adds it to the front of the list
precondition: none
postcondition: Must correctly create the list element and add it to the correct location in the list
*/
Element * addToFront(void * structPtr,Element * list, int ptrSize);
/*Creates a new List elementand adds it to the back of the list
precondition: none
postcondition: Must correctly create the list element and add it to the correct location in the list
*/
Element * addToBack(void * structPtr,Element * list, int ptrSize);
/*Removes the front element of the list
precondition: Must have a list with elements to delete from
postcondition: Must delete the appropriate element, and return the list correctly
*/
Element * removeFromFront(Element * list);
/*Removes the back element of the lsit
precondition: Must have a list with elements to delete from
postcondition: Must delete the appropriate element, and return the list correctly
*/
Element * removeFromBack(Element * list);
/*Deletes the list and frees the pointers
precondition: Must have a list to delete
postcondition: List must be deleted and memory freed
*/
Element * deleteList(Element * list);
/*Returns the struct positioned in the first element in the list
precondition: Must have a list with elements to read from
postcondition: Must return a valid struct (if there is one to return)
*/
void * getValueFront(Element * list);
/*Returns the struct positioned in the last element in the list
precondition: Must have a list with elements to read from
postcondition: Must return a valid struct (if there is one to return)
*/
void * getValueBack(Element * list);
/*Returns the number of elements in the list (0 if empty)
precondition: None
postcondition: Must return a valid value
*/
int getSize(Element * list);

#endif