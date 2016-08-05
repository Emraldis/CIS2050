#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DataInfo{
	int data;
}Data;

Data * createData(int input);

int compareData(void const * dataA,void const * dataB);

void deleteData(void const * input);

void printData(void const * input);
