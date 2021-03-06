#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mazeData.h"
#include "stackADT.h"

/*Alpheaus Feltham, 0903594*/

int main(int argc, char * argv[]){
	FILE * mazeData;
	char * string;
	char * fileName;
	Maze * maze;
	int sizeX = 0;
	int sizeY = 0;
	int i = 0;
	int j = 0;
	int startX;
	int startY;
	int loc[2];
	char testChar = 'a';
	PathData * path;
	Stack * stack;
	PathData * tempPath;
	PathData * newPath;
	
	fileName = malloc(sizeof(char) * 256);
	
	if(argv[1] != NULL){
		strcpy(fileName,argv[1]);
	}
	printf("\nopening maze file\n");
	getchar();
	mazeData = fopen(fileName,"r");
	if(mazeData != NULL){
		printf("\nFile Opened Successfully!");
		getchar();
		maze = malloc(sizeof(maze));
		printf("\nMemory Allocated for maze");
		getchar();
		string = malloc(sizeof(char) * 128);
		printf("\nMemory Allocated for string");
		getchar();
		stack = NULL;
		tempPath = malloc(sizeof(PathData));
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
		stack = addToStack(path,stack,sizeof(PathData));
		tempPath = readFromTop(stack);
		
		if(tempPath == NULL){
			printf("\nERROR\n");
			exit(0);
		}
		
		
		printf("\nBeginning solution");
		getchar();
		// && (tempPath->available[0] != 'X'))
		while(maze->mazeData[loc[0]][loc[1]] != 'F'){
			while((tempPath->available[0] == 'X') && (maze->mazeData[tempPath->locX][tempPath->locY] != 'F')){
				if(maze->mazeData[tempPath->locX][tempPath->locY] == '*'){
					maze->mazeData[tempPath->locX][tempPath->locY] = ' ';
				}
				stack = removeFromStack(stack);
				tempPath = readFromTop(stack);
			}
			newPath = setNewPos(tempPath,maze);
			//printf("\nTEST: %s\n",newPath->available);
			stack = addToStack(newPath,stack,sizeof(PathData));
			tempPath = readFromTop(stack);
			for(j=0;j<sizeY;j++){
				printf("%s",maze->mazeData[j]);
			}
			loc[0] = tempPath->locX;
			loc[1] = tempPath->locY;
		}
		printf("\n***********Solution Complete**********\n");
		/*for(j=0;j<sizeY;j++){
			printf("%s",maze->mazeData[j]);
		}*/
		
	}else{
		printf("\nERROR opening file");
	}
	printf("\n");
	
	return(0);
}