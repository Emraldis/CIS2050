#include "mazeData.h"

/*Alpheaus Feltham, 0903594*/

Path * create(char * value){
	
}

void deleteStruct(Path * path){
	free(path->available);
	free(path->used);
	free(path);
}