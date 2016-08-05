#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DataInfo{
	int data;
}Data;

Data * createData(int input);

int compareData(const void * dataA,const void * dataB);

void deleteData(Data * input);

void printData(const void * input);
