#include "mazeData.h"

/*Alpheaus Feltham, 0903594*/

Path * create(int locX, int locY, Maze * maze){
	Path * path;
	path = malloc(sizeof(Path));
	path->available = malloc(sizeof(char) * 4);
	path->used = malloc(sizeof(char) * 4);
	strcpy(path->available,getOptions(maze,locX,locY));
	maze->mazeData[locX][locY] = '*';
	printf("\nTEST A: %s\n",path->available);
	getchar();
	path->locX = locX;
	path->locY = locY;
	printf("\nTEST B: %s\n",path->available);
	getchar();
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
			options[i] = 'D';
		}
	}
	if(posY > 0){
		if(maze->mazeData[posX][posY - 1] == ' '){
			options[i] = 'U';
		}
	}
	
	//printf("\nTEST:%s\n",options);
	return(options);
}

Path * setNewPos(Path * path, Maze * maze){
	Path * newPath;
	int newX;
	int newY;
	
	printf("\n%s @ %d,%d\n",path->available, path->locX,path->locY);
	
	switch(path->available[0]){
		case 'R':
			printf("The option to be used is: R");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = (path->locX + 1);
			newY = path->locY;
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			getchar();
			break;
		case 'L':
			printf("The option to be used is: L");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = (path->locX - 1);
			newY = path->locY;
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			getchar();
			break;
		case 'U':
			printf("The option to be used is: U");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = path->locX;
			newY = (path->locY - 1);
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			getchar();
			break;
		case 'D':
			printf("The option to be used is: D");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newX = path->locX;
			newY = (path->locY + 1);
			printf("\nThe next location will be at %d,%d\n",newX,newY);
			newPath = create(newX,newY,maze);
			printf("\nNew path created, location %d,%d\n",newPath->locX,newPath->locY);
			getchar();
			break;
		default:
			printf("\nError encountered while attempting to solve maze.\n");
			exit(0);
	}
	printf("TEST: %s\n",newPath->available);
	return(newPath);
}