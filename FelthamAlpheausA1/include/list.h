#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement{
	void * structPtr;
	struct ListElement * next;
}Element;
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
Element * createList(void * structPtr);
/*Creates a new List element and adds it to the front of the list
precondition: none
postcondition: Must correctly create the list element and add it to the correct location in the list
*/
Element * addToFront(void * structPtr,Element * list);
/*Creates a new List elementand adds it to the back of the list
precondition: none
postcondition: Must correctly create the list element and add it to the correct location in the list
*/
Element * addToBack(void * structPtr,Element * list);
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
void deleteList(Element * list);
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