#include "testData.h"

Data * createData(int input){
	Data * newData;
	
	newData = malloc(sizeof(Data));
	
	newData->data = input;
	
	return(newData);
}

int compareData(const void * dataA,const void * dataB){
	Data * data1;
	Data * data2;
	
	data1 = malloc(sizeof(Data));
	data2 = malloc(sizeof(Data));
	
	memcpy(data1,dataA,sizeof(Data));
	memcpy(data2,dataB,sizeof(Data));
	
	if(data1->data < data2->data){
		return(-1);
	}else if(data1->data == data2->data){
		return(0);
	}else if(data1->data > data2->data){
		return(1);
	}
	printf("\nERROR");
	exit(0);
}

void deleteData(Data * input){
	free(input);
}

void printData(const void * input){
	Data * tempData;
	
	if(input != NULL){
		tempData = malloc(sizeof(Data));
		
		memcpy(tempData,input,sizeof(Data));
		
		printf("\nDATA: %d",tempData->data);
		
		free(tempData);
	}else{
		printf("\nEMPTY");
	}
}