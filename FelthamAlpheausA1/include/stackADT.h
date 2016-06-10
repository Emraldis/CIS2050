#include "listADT.h"

typedef struct StackElement{
	void * structPtr;
	struct StackElement * under;
}Stack;
/*Creates a new Stack element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
Stack * createStack(void * structPtr);
/*Creates a new Stack element and adds it to the top of the Stack
precondition: none
postcondition: Must correctly create the Stack element and add it to the correct location in the stack
*/
Stack * addToStack(void * structPtr,Stack * stack);
/*Removes the top element of the stack and frees the memory
precondition: Must have a stack with elements to delete from
postcondition: Must delete the appropriate element, and return the stack correctly
*/
Stack * removeFromStack(Stack * stack);
/*Deltes the stack pointers and frees the memory
precondition: Must have a stack to delete
postcondition: Stack must be deleted and memory freed
*/
void deleteStack(Stack * stack);
/*Returns the struct positioned in the top element of the stack
precondition: Must have a stack with elements to read from
postcondition: Must return a valid struct (if there is one to return)
*/
void * readFromTop(Stack * stack);