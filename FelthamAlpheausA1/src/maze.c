#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mazeData.h"
#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

int main(void){
	FILE * mazeData;
	char * string;
	int i = 0;
	
	mazeData = fopen("maze","r");
	string = malloc(sizeof(char) * 128);
	
	printf("\nopening maze file");
	getchar();
	if(mazeData != NULL){
		while ((string != NULL) && (i<100){
			fgets(string,128,mazeData);
			printf("\n%s",string);
			i++;
		}
	}else{
		printf("ERROR opening file");
	}
	printf("\nDone");
	
	return(0);
}