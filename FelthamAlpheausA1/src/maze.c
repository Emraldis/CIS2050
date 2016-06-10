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
	int sizeY = 0;
	int i = 0;
	int j = 0;
	int startX;
	int startY;
	
	mazeData = fopen("maze","r");
	string = malloc(sizeof(char) * 128);
	mazeLayer = malloc(sizeof(char));
	maze = malloc(sizeof(char *));
	
	printf("\nopening maze file");
	if(mazeData != NULL){
		while ((fgets(string,128,mazeData) != NULL) && (i<101)){
			if(strlen(string) > sizeX){
				sizeX = strlen(string);
			}
			realloc(mazeLayer,sizeof(char) * sizeX);
			strcpy(mazeLayer,string);
			getchar();
			sizeY++;
			realloc(maze,sizeof(char) * sizeY);
			strcpy(maze[i],mazeLayer);
			printf("%s",maze[i]);
			i++;
		}
	}else{
		printf("\nERROR opening file");
	}
	printf("\nDone");
	
	return(0);
}