#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

Stack * createStack(void * structPtr, int ptrSize){
	Stack * stack;
	stack = malloc(sizeof(Stack));
	stack->structPtr = malloc(ptrSize);
	memcpy(stack->structPtr,structPtr,ptrSize);
	stack->ptrSize = ptrSize;
	stack->under = NULL;
	
	return(stack);
}
Stack * addToStack(void * structPtr, Stack * stack, int ptrSize){
	Stack * element;
	
	element = createStack(structPtr,ptrSize);
	element->under = stack;
	return(element);
}
Stack * removeFromStack(Stack * stack){
	Stack * temp;
	
	if(stack != NULL){
		temp = stack;
		stack = stack->under;
		free(temp->structPtr);
		free(temp);
	}else{
		printf("\nStack is empty");
	}
	return(stack);
}
Stack * deleteStack(Stack * stack){
	Stack * tempStack;
	
	while(stack != NULL){
		tempStack = stack;
		stack = stack->under;
		free(tempStack->structPtr);
		free(tempStack);
	}
	stack = NULL;
	return(stack);
}
void * readFromTop(Stack * stack){
	void * ptr;
	if(stack != NULL){
		ptr = malloc(stack->ptrSize);
		memcpy(ptr,stack->structPtr,stack->ptrSize);
		return(ptr);
	}else{
		return(NULL);
	}
}