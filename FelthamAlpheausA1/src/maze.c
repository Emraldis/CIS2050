#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mazeData.h"
#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

int main(void){
	FILE * mazeData;
	char * string;
	Maze * maze;
	int sizeX = 0;
	int sizeY = 0;
	int i = 0;
	int j = 0;
	int startX;
	int startY;
	char testChar = 'a';
	Path * path;
	
	mazeData = fopen("maze","r");
	string = malloc(sizeof(char) * 128);
	
	printf("\nopening maze file\n");
	if(mazeData != NULL){
		while ((fgets(string,128,mazeData) != NULL) && (i<101)){
			if(strlen(string) > sizeX){
				sizeX = strlen(string);
			}
			sizeY++;
			i++;
		}
		fclose(mazeData);
		maze->mazeData = malloc(sizeof(char *) * sizeY);
		maze->sizeX = sizeX;
		maze->sizeY = sizeY;
		mazeData =fopen("maze","r");
		i = 0;
		while(fgets(string,128,mazeData)){
			for(j=0;j<sizeX;j++){
				testChar = string[j];
				if(testChar == 'S'){
					startX = j;
					startY = i;
				}
			}
			maze->mazeData[i] = malloc(sizeof(char) * sizeX);
			strcpy(maze->mazeData[i],string);
			i++;
		}
		fclose(mazeData);
		printf("\nThe start position of the maze is located at %d,%d\n",startX,startY);
		for(j=0;j<sizeY;j++){
			printf("%s",maze->mazeData[j]);
		}
		path = create(startX,startY,maze);
	}else{
		printf("\nERROR opening file");
	}
	printf("\n");
	
	return(0);
}