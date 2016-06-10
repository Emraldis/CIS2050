#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "testData.h"
#include "stackADT.h"

int main(void){
	int i;
	char * string;
	Test * data;
	Element * list;
	void * dataPtr;
	Element * currentPos;
	
	string = malloc(sizeof(char) * 128);
	list = NULL;
	dataPtr = NULL;
	
	printf("\nTesting List ADT:");
	getchar();
	printf("\nCreating List");
	for(i=1;i<101;i++){
		sprintf(string,"%d",i);
		printf("step one");
		getchar();
		data = create(string);
		printf("step two");
		getchar();
		//memcpy(dataPtr,data,sizeof(data));
		//printf("step three");
		//getchar();
		list = addToFront(&data,list,sizeof(data));
		printf("step four");
		getchar();
	}
	getchar();
	printf("\nPrinting List:");
	currentPos = list;
	while(currentPos != NULL){
		printData(currentPos->structPtr);
	}
	
	return(0);
}