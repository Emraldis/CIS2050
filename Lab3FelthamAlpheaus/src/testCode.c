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
	getchar();
	printf("\nPrinting the stack");
	getchar();
	printStack(stack);
	printf("\nRemoving the top element of the stack, and printing again");
	getchar();	
	stack = removeFromTop(stack);
	printStack(stack);
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	getchar();
	printf("\nDeleting the stack, and then printing again");
	getchar();	
	stack = deleteStack(stack);
	printStack(stack);
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	getchar();
	printf("\nAttempting to delete an empty stack");
	getchar();
	stack = deleteStack(stack);
	printf("\nAttempting to remove the top element of an empty stack");
	getchar();
	stack = removeFromTop(stack);
	printf("\nAttempting to add an element to an empty stack");
	getchar();	
	stack = addToStack("1",stack);	
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	getchar();
	printf("\nPrinting the stack");
	getchar();	
	printStack(stack);
	printf("\nAdding an element with an empty value");
	getchar();
	stack = addToStack(NULL,stack);
	printf("\nThe value of the element on top of the stack is: %s",getTopValue(stack));
	getchar();
	printf("\n");
	
	return(0);
}