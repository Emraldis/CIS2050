#include "mazeData.h"

/*Alpheaus Feltham, 0903594*/

Path * create(int locX, int locY, Maze * maze){
	Path * path;
	path = malloc(sizeof(path));
	path->available = malloc(sizeof(char) * 4);
	path->used = malloc(sizeof(char) * 4);
	path->locArr[0] = locX;
	path->locArr[1] = locY;
	path->available = getOptions(maze,locX,locY);
	return(path);
}

void deleteStruct(Path * path){
	free(path->available);
	free(path->used);
	free(path);
}

char * getOptions(Maze * maze, int posX, int posY){
	char * options;
	int i;
	
	i = 0;
	options = malloc(sizeof(char) * 4);
	
	strcpy(options,"XXXX");
	
	getchar();
	
	if(posX < maze->sizeX){
		if(maze->mazeData[posX + 1][posY] == ' '){
			options[i] = 'R';
		}
	}
	if(posX > 0){
		if(maze->mazeData[posX - 1][posY] == ' '){
			options[i] = 'L';
		}
	}
	if(posY < maze->sizeY){
		if(maze->mazeData[posX][posY + 1] == ' '){
			options[i] = 'U';
		}
	}
	if(posY > 0){
		if(maze->mazeData[posX][posY - 1] == ' '){
			options[i] = 'D';
		}
	}
	
	printf("\n%s\n",options);
	
	return(options);
}