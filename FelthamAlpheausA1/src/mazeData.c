#include "mazeData.h"

/*Alpheaus Feltham, 0903594*/

Path * create(int locX, int locY, Maze * maze){
	Path * path;
	path = malloc(sizeof(path));
	path->available = malloc(sizeof(char) * 4);
	path->used = malloc(sizeof(char) * 4);
	path->locArr[0] = locX;
	path->locArr[1] = locY;
	strcpy(path->available,getOptions(maze,locX,locY));
	maze->mazeData[locX][locY] = '*';
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
	
	
	return(options);
}

Path * setNewPos(Path * path, Maze * maze){
	Path * newPath;
	
	printf("\n%s\n",path->available);
	
	getchar();
	
	switch(path->available[0]){
		case 'R':
			printf("The option to be used is: R");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newPath = create((path->locArr[0] + 1),path->locArr[1],maze);
			break;
		case 'L':
			printf("The option to be used is: L");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newPath = create((path->locArr[0] - 1),path->locArr[1],maze);
			break;
		case 'U':
			printf("The option to be used is: U");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newPath = create(path->locArr[0],(path->locArr[1] + 1),maze);
			break;
		case 'D':
			printf("The option to be used is: D");
			getchar();
			path->available[0] = path->available[1];
			path->available[1] = path->available[2];
			path->available[2] = path->available[3];
			path->available[3] = 'X';
			newPath = create(path->locArr[0],(path->locArr[1] - 1),maze);
			break;
		default:
			printf("\nError encountered while attempting to solve maze.\n");
			exit(0);
	}
	return(newPath);
}