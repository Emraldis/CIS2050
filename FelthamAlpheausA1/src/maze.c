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
	int sizeX = 0;
	int sizeY = 0;
	int i = 0;
	int j = 0;
	int startX;
	int startY;
	
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
		maze = malloc(sizeof(char *) * sizeY);
		mazeData =fopen("maze","r");
		i = 0;
		while(fgets(string,128,mazeData)){
			for(j=0;j<sizeX;j++){
				printf("\n%d",i);
				if(string[j] == 'S');{
					startX = j;
					startY = i;
					printf("\nThe start position of the maze is located at %d,%d",startX,startY);
				}
			}
			maze[i] = malloc(sizeof(char) * sizeX);
			strcpy(maze[i],string);
			i++;
		}
		fclose(mazeData);
		printf("\nThe start position of the maze is located at %d,%d\n",startX,startY);
		for(j=0;j<sizeY;j++){
			printf("%s",maze[j]);
		}
	}else{
		printf("\nERROR opening file");
	}
	printf("\n");
	
	return(0);
}