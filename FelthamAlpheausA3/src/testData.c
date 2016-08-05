#include "testData.h"

Data * createData(int input){
	Data * newData;
	
	newData = malloc(sizeof(Data));
	
	newData->data = input;
	
	return(newData);
}

int compareData(Data * data1,Data * data2){
	if(data1->data < data2->data){
		return(-1);
	}else if(data1->data = data2->data){
		return(0);
	}else if(data1->data > data2->data){
		return(1);
	}
}

void deleteData(Data * input){
	free(input);
}

void printData(Data * input){
	printf("\nDATA: %d",input->input);
}