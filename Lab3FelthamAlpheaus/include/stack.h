#include <stdio.h>
#include <stdlib.h>

typedef struct Stackinfo{
	char * value;
	struct Stackinfo * previous;
	struct Stackinfo * top;
}Stack;

Stack * createStack(char * value);

Stack * addToStack(char * value, Stack * stack);

char * getTopValue(Stack * stack);

Stack * removeFromTOp(Stack * stack);

void deleteStack(Stack * stack);

void printStack(Stack * stack);