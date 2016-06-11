#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mazeData.h"
#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

int main(void){
	FILE * mazeData;
	char * string;
	char * * maze;
	char * mazeLayer;
	int sizeX = 0;
	int sizeY = 1;
	int i = 0;
	int j = 0;
	int startX;
	int startY;
	
	mazeData = fopen("maze","r");
	string = malloc(sizeof(char) * 128);
	
	printf("\nopening maze file");
	if(mazeData != NULL){
		while ((fgets(string,128,mazeData) != NULL) && (i<101)){
			if(strlen(string) > sizeX){
				sizeX = strlen(string);
			}
			sizeY++;
			printf("%s",string);
			i++;
		}
		fclose(mazeData);
		maze = malloc(sizeof(char *) * sizeY);
		mazeData =(fopen("maze","r");
		i = 0;
		while(fgets(string,128,mazeData){
			maze[i] = malloc(sizeof(char) * sizeX);
			strcpy(maze[i],string);
			i++;
		}
	}else{
		printf("\nERROR opening file");
	}
	printf("\n");
	
	return(0);
}