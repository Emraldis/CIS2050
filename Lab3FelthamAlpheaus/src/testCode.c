#include <stdio.h>
#include "stack.h"

int main(void){
	Stack * stack;
	char * tempValue;
	int i;
	
	stack = createStack("1");
	tempValue = malloc(sizeof(char) * 128);
	
	for(i=2;i<101;i++){
		sprintf(tempValue,"%d",i);
		stack = addToStack(tempValue,stack);
	}
	
	printStack(stack);
	
	return(0);
}