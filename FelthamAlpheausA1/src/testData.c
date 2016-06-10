#include "testData.h"

Test * create(char * value){
	Test * test;
	
	test = malloc(sizeof(test));
	test->value = malloc(sizeof(char) * 128);
	strcpy(test->value,value);
	
	return(test);
}

void deleteStruct(Test * input){
	free(input->value);
	free(input);
}

void printData(Test * input){
	printf("\n%s",input->value);
}