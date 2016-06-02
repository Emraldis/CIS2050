#include "stack.h"

Stack * createStack(char * value){
	Stack * stack;
	
	stack = malloc(sizeof(stack));
	stack->value = malloc(sizeof(char) * 128);
	stack->value = value;
	stack->previous = NULL;
	stack->top = stack;
	
	return(stack);
}

Stack * addToStack(char * value, Stack * stack){
	Stack * element;
	
	element = createStack(value);
	element->previous = stack->top;
	stack->top = element;
	
	return(stack);
}

char * getTopValue(Stack * stack){
	return(stack->top->value);
}

Stack * removeFromTOp(Stack * stack){
	Stack * tempStack;
	
	if(stack->previous != NULL){
		tempStack = stack->top;
		stack->top = stack->top->previous;
		free(tempStack->value);
		free(tempStack);
	}else{
		free(stack->value);
		free(stack);
		stack = NULL;
	}
	
	return(stack);
}

void deleteStack(Stack * stack){
	Stack * tempStack;
	Stack * currentStack;
	
	tempStack = stack->top;
	currentStack = tempStack;
	while(currentStack != NULL){
		free(tempStack->value);
		currentStack = currentStack->previous;
		free(tempStack);
		tempStack = currentStack;
	}
	
}

void printStack(Stack * stack){
	Stack * currentStack;
	
	currentStack = stack->top;
	
	while(currentStack != NULL){
		printf("\n%s",currentStack->value);
		currentStack = currentStack->previous;
	}
}