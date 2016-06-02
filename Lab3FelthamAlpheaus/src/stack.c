#include "stack.h"

/*Alpheaus Feltham, 0903594*/

/*Creates a new Stack element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
Stack * createStack(char * value){
	Stack * stack;
	
	stack = malloc(sizeof(stack));
	stack->value = malloc(sizeof(char) * 128);
	strcpy(stack->value,value);
	stack->previous = NULL;
	stack->top = stack;
	
	return(stack);
}

/*Creates a new Stack element and adds it to the top of the stack
precondition: none (will make a new stack if a NULL stack is given)
postcondition: Must output a valid correctly create a stack element, and place it on top of the stack.
*/
Stack * addToStack(char * value, Stack * stack){
	Stack * element;
	
	element = createStack(value);
	if(stack != NULL){
		element->previous = stack->top;
		stack->top = element;
	}else{
		stack = element;
	}
	
	return(stack);
}

/*Returns the value of the element on top of the stack
precondition: There must be an element to take a value from
postcondition: Must return either a valid value, or correct error message
*/
char * getTopValue(Stack * stack){
	if(stack != NULL){
		if(stack->top->value != NULL){
			return(stack->top->value);
		}else{
			return("\nElement present, but value is empty");
		}
	}else{
		return("EMPTY");
	}
}

/*Removes an element from the top of the stack
precondition: There must be an element to remove, or a stack to remove an element from
postcondition: Must remove the correct element, and correctly return the stack, if the stack was one unit large, then it must return the empty stack
*/
Stack * removeFromTop(Stack * stack){
	Stack * tempStack;
	
	if(stack != NULL){
		if(stack->top->previous != NULL){
			tempStack = stack->top;
			stack->top = stack->top->previous;
			free(tempStack->value);
			free(tempStack);
		}else{
			free(stack->value);
			free(stack);
			stack = NULL;
		}
	}else{
		printf("\nNothing in stack to delete");
	}
	
	return(stack);
}

/*Deletes a stack and frees the memory
precondition: There must be a stack to delete
postcondition: Must correctly delete the values within the stack and return a NULL value for the stack pointer to point to
*/
Stack * deleteStack(Stack * stack){
	Stack * tempStack;
	Stack * currentStack;
	
	if(stack != NULL){
		tempStack = stack->top;
		currentStack = tempStack;
		while(currentStack != NULL){
			free(tempStack->value);
			currentStack = currentStack->previous;
			free(tempStack);
			tempStack = currentStack;
		}
	}else{
		printf("\nNothing to delete");
	}
	
	return(NULL);
}

/*Prints all of the values in the stack from the element on top to the element on the bottom
precondition: Must have elements to print the value from
postcondition: Must correctly print the element values in the right order.
*/
void printStack(Stack * stack){
	Stack * currentStack;
	
	if(stack != NULL){
		currentStack = stack->top;
		while(currentStack != NULL){
			printf("\n%s",currentStack->value);
			currentStack = currentStack->previous;
		}
	}else{
		printf("\nEmpty stack");
	}
}