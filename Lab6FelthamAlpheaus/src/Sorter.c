#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]){
	int * * hashMap;
	int * mapEntry;
	char * tempString;
	int size;
	FILE * inputFile;
	FILE * outputFile;
	char * fileName;
	int i = 0;
	char * truncString;
	char * truncStringTwo;
	int collisions = 0;
	char * outputString;
	char * tempOutputString;
	
	inputFile = fopen("numList","r");
	if(inputFile != NULL){
		printf("\nFile Opened\n");
	}else{
		printf("\nError opening file.\n");
		exit(0);
	}
	tempString = malloc(sizeof(char) * 256);
	truncString = malloc(sizeof(char) * 4);
	truncStringTwo = malloc(sizeof(char) * 4);
	mapEntry = malloc(sizeof(int) * 2);
	fileName = malloc(sizeof(char) * 256);
	outputString = malloc(sizeof(char) * 256);
	tempOutputString = malloc(sizeof(char) * 256);
	if(argv[1] != NULL){
		tempString = argv[1];
		sprintf(fileName,"size%s.txt",tempString);
		outputFile = fopen(fileName,"w");
		size = atoi(tempString);
	}else{
		size = 100;
		sprintf(fileName,"size%d.txt",size);
		outputFile = fopen(fileName,"w");
	}
	hashMap = malloc(sizeof(int *) * size);
	
	printf("\nBeginning sorting\n");
	
	while((i <300) && (fgets(tempString,256,inputFile) != NULL)){
		i++;
		truncString[0] = tempString[0];
		truncString[1] = tempString[1];
		truncString[2] = tempString[2];
		if(tempString[3] != NULL){
			truncStringTwo[0] = tempString [3];
			if(tempString[4] != NULL){
				truncStringTwo[1] = tempString [4];
				if(tempString[3] != NULL){
					truncStringTwo[2] = tempString [5];
				}else{
					truncStringTwo[2] = "0";
				}
			}else{
				truncStringTwo[1] = "0";
			}
		}else{
			truncStringTwo[0] = "0";
		}
		sprintf(tempOutputString," From:(%s * %s) \% %d",truncString,truncStringTwo,size);
		
		mapEntry[0] = ((atoi(truncString) * (atoi(truncStringTwo))) % size);
		mapEntry [1] = atoi(tempString);
		sprintf(outputString,"Generated key of: %d for data value: %d %s",mapEntry[0], mapEntry[1],tempOutputString);
		fputs(outputString,outputFile);
		if(hashMap[mapEntry[0]] == NULL){
			fputs("\n",outputFile);
			hashMap[mapEntry[0]] = mapEntry;
		}else{
			sprintf(outputString,"But There was a collision, as key: %d was already taken\n",mapEntry[0]);
			fputs(outputString,outputFile);
			printf("collision at %d\n", mapEntry[0]);
			collisions++;
		}
	}
	sprintf(outputString,"\nTotal number of collisions: %d\n", collisions);
	printf("\nTotal number of collisions: %d\n", collisions);
	fputs(outputString,outputFile);
	fclose(inputFile);
	fclose(outputFile);
	return(0);
}