#include <stdio.h>
#include <stdlib.h>

typedef struct Stackinfo{
	char * value;
	struct Stack previous;
	struct Stack top;
}Stack;

Stack * createStack(char * value);

Stack * addToStack(char * value, Stack * stack);

char * getTopValue(Stack * stack);

Stack * removeFromTOp(Stack * stack);

void deleteStack(Stack * stack);

void printStack(Stack * stack);