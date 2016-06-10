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
	
	while (string != NULL){
		fgets(string,128,mazeData);
		printf("\n%s",string);
	}
	printf("\n");
	
	return(0);
}