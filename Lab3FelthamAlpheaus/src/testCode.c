#include <stdio.h>
#include "stack.h"

/*Alpheaus Feltham, 0903594*/

int main(void){
	Stack * stack;
	char * tempValue;
	int i;
	
	printf("\nCreating a new Stack");
	
	stack = createStack("1");
	tempValue = malloc(sizeof(char) * 128);
	
	for(i=2;i<101;i++){
		sprintf(tempValue,"%d",i);
		stack = addToStack(tempValue,stack);
	}
	
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	printf("\nPrinting the stack");
	printStack(stack);
	printf("\nRemoving the top element of the stack, and printing again");
	stack = removeFromTop(stack);
	printStack(stack);
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	printf("\nDeleting the stack, and then printing again");
	stack = deleteStack(stack);
	printStack(stack);
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	printf("\nAttempting to delete an empty stack");
	stack = deleteStack(stack);
	printf("\nAttempting to remove the top element of an empty stack");
	stack = removeFromTop(stack);
	printf("\nAttempting to add an element to an empty stack");
	stack = addToStack("1",stack);	
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	printf("\nPrinting the stack");
	printStack(stack);
	printf("\nAdding an element with an empty value");
	stack = addToStack(NULL,stack);
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	printf("\nPrinting the stack");	
	printStack(stack);
	printf("\n");
	
	return(0);
}