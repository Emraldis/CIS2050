#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	FILE * outputFile;
	time_t t;
	srand((unsigned)time(&t));
	char * tempString;
	int i;
	int tempInt;
	
	tempString = malloc(sizeof(char) * 256);
	
	outputFile = fopen("numList", "w");
	
	for(i=0;i<300;i++){
		tempInt = (rand() % 3000000);
		sprintf(tempString,"%d\n",tempInt);
		fputs(tempString,outputFile);
	}
	fclose(outputFile);
}