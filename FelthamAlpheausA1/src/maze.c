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
	int loc[2];
	char testChar = 'a';
	Path * path;
	Stack * stack;
	Path * tempPath;
	Path * newPath;
	
	mazeData = fopen("maze","r");
	maze = malloc(sizeof(maze));
	string = malloc(sizeof(char) * 128);
	stack = NULL;
	
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
		loc[0] = startX;
		loc[1] = startY;
		fclose(mazeData);
		printf("\nThe start position of the maze is located at %d,%d",startX,startY);
		printf("\nThe maze is %d by %d units in size\n",maze->sizeX, maze->sizeY);
		for(j=0;j<sizeY;j++){
			printf("%s",maze->mazeData[j]);
		}
		path = create(startX,startY,maze);
		printf("\nTEST1:%s\n",path->available);
		stack = addToStack(path,stack,sizeof(path));
		tempPath = readFromTop(stack);
		
		printf("\nTEST2:%s\n",tempPath->available);
		
		printf("\nBeginning solution");
		getchar();
		
		while((maze->mazeData[loc[0]][loc[1]] != 'F') && (tempPath->available[0] != 'X')){
			newPath = setNewPos(tempPath,maze);
			stack = addToStack(newPath,stack,sizeof(newPath));
			tempPath = readFromTop(stack);
			
		}
		for(j=0;j<sizeY;j++){
			printf("%s",maze->mazeData[j]);
		}
		
	}else{
		printf("\nERROR opening file");
	}
	printf("\n");
	
	return(0);
}