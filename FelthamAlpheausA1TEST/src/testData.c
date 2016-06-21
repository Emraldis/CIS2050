#include "testData.h"

/*Alpheaus Feltham, 0903594*/

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
	if(input != NULL){
		printf("\n%s",input->value);
	}else{
		printf("\nEMPTY");
	}
}