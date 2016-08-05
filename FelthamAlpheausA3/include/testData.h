#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DataInfo{
	int data;
}Data;

Data * createData(int input);

int compareData(void * data1,void * data2);

void deleteData(Data * input);

void printData(Data * input);
