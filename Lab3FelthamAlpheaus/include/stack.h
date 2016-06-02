#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Alpheaus Feltham, 0903594*/

typedef struct Stackinfo{
	char * value;
	struct Stackinfo * previous;
	struct Stackinfo * top;
}Stack;

Stack * createStack(char * value);

Stack * addToStack(char * value, Stack * stack);

char * getTopValue(Stack * stack);

Stack * removeFromTop(Stack * stack);

Stack * deleteStack(Stack * stack);

void printStack(Stack * stack);