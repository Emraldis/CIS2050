#include "stack.h"

Stack * createStack(char * value){
	Stack * stack;
	
	stack = malloc(sizeof(stack));
	stack->value = malloc(sizeof(char) * 128);
	strcpy(stack->value,value);
	stack->previous = NULL;
	stack->top = stack;
	
	return(stack);
}

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

char * getTopValue(Stack * stack){
	if(stack != NULL){
		return(stack->top->value);
	}else{
		return("EMPTY");
	}
}

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
		printf("\nEmpty Stack");
	}
	
	return(stack);
}

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