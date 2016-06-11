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
	options = malloc(sizeof(char) * 4);
	return(options);
}