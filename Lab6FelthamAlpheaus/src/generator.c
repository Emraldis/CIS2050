#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	FILE * outputFile;
	srand(time_t);
	char * tempString;
	int i;
	int tempInt;
	
	tempString = malloc(sizeof(char) * 256);
	
	for(i=0;i<300;i++){
		tempInt = (rand() % 3000000);
		sprintf(tempString,"%d\n",tempInt);
	}
	
	outputFile = fopen("numList", "w");
}