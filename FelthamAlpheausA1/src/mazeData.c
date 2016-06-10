#include "mazeData.h"

/*Alpheaus Feltham, 0903594*/

Path * create(char * value){
	Path * path;
	path = malloc(sizeof(path));
	return(path);
}

void deleteStruct(Path * path){
	free(path->available);
	free(path->used);
	free(path);
}

char * getOptions(char * * maze, int posX, int posY){
	char * options;
	options = malloc(sizeof(char) * 128);
	return(options);
}