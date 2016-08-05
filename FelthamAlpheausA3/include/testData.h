#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DataInfo{
	int data;
}Data;

Data * createData(int input);

int compareData(void * dataA,void * dataB);

void deleteData(Data * input);

void printData(Data * input);
