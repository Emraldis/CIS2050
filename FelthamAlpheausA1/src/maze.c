#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mazeData.h"
#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

int main(void){
	FILE * mazeData;
	char * string;
	
	mazeData = fopen("maze","r");
	string = malloc(sizeof(char) * 128);
	
	printf("\nopening maze file");
	getchar();
	if(mazeData != NULL){
		while (string != NULL){
			printf("\ntest1");
			getchar();
			fgets(string,128,mazeData);
			printf("\ntest2");
			getchar();
			printf("\n%s",string);
		}
	}else{
		printf("ERROR opening file");
	}
	printf("\n");
	
	return(0);
}