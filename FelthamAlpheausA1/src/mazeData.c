#include "mazeData.h"

/*Alpheaus Feltham, 0903594*/

PathData * create(int locX, int locY, Maze * maze){
	PathData * path;
	path = malloc(sizeof(PathData));
	path->available = malloc(sizeof(char) * 4);
	strcpy(path->available,getOptions(maze,locX,locY));
	if(maze->mazeData[locX][locY] == ' '){
		maze->mazeData[locX][locY] = '*';
	}
	path->locX = locX;
	path->locY = locY;
	return(path);
}

void deleteStruct(PathData * path){
	free(path->available);
	free(path);
}

char * getOptions(Maze * maze, int posX, int posY){
	char * options;
	int i;
	
	options = malloc(sizeof(char) * 4);
	
	strcpy(options,"XXXX");
	
	if(posX < maze->sizeX){
		if((maze->mazeData[posX + 1][posY] == ' ') || (maze->mazeData[posX + 1][posY] == 'F')){
			i = 0;
			while(options[i] != 'X'){
				i++;
			}
			options[i] = 'R';
			printf("\nTo the right, the character is: '%c'",maze->mazeData[posX + 1][posY]);
		}
	}
	if(posX > 0){
		if((maze->mazeData[posX - 1][posY] == ' ') || (maze->mazeData[posX - 1][posY] == 'F')){
			i = 0;
			while(options[i] != 'X'){
				i++;
			}
			options[i] = 'L';
			printf("\nTo the left, the character is: '%c'",maze->mazeData[posX - 1][posY]);
		}
	}
	if(posY < maze->sizeY){
		if((maze->mazeData[posX][posY + 1] == ' ') || (maze->mazeData[posX][posY + 1] == 'F')){
			i = 0;
			while(options[i] != 'X'){
				i++;
			}
			options[i] = 'D';
			printf("\nTo the bottom, the character is: '%c'",maze->mazeData[posX][posY + 1]);
		}
	}
	if(posY > 0){
		if((maze->mazeData[posX][posY - 1] == ' ') || (maze->mazeData[posX][posY - 1] == 'F')){
			i = 0;
			while(options[i] != 'X'){
				i++;
			}
			options[i] = 'U';
			printf("\nTo the top, the character is: '%c'",maze->mazeData[posX][posY - 1]);
		}
	}
	
	printf("\nTEST:%s\n",options);
	return(options);
}

PathData * setNewPos(PathData * path, Maze * maze){
	PathData * newPath;
	int newX;
	int newY;
	
	printf("\n%s @ %d,%d\n",path->available, path->locX,path->locY);
	
	switch(path->available[0]){
		case 'R':
			printf("The option to be used is: R");
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = (path->locX + 1);
			newY = path->locY;
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			break;
		case 'L':
			printf("The option to be used is: L");
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = (path->locX - 1);
			newY = path->locY;
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			break;
		case 'U':
			printf("The option to be used is: U");
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = path->locX;
			newY = (path->locY - 1);
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			break;
		case 'D':
			printf("The option to be used is: D");
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = path->locX;
			newY = (path->locY + 1);
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			break;
		default:
			printf("\nError encountered while attempting to solve maze.\n");
			exit(0);
	}
	return(newPath);
}