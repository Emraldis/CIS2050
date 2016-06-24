#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]){
	int * * hashMap;
	int * mapEntry;
	char * tempString;
	int size;
	FILE * inputFile;
	int i = 0;
	char * truncString;
	int collisions = 0;
	
	inputFile = fopen("numList","r");
	tempString = malloc(sizeof(char) * 256);
	truncString = malloc(sizeof(char) * 4);
	mapEntry = malloc(sizeof(int) * 2);
	tempString = argv[1];
	size = atoi(tempString);
	hashMap = malloc(sizeof(int *) * size);
	
	while((i <size) && (fgets(tempString,256,inputFile) != NULL)){
		i++;
		truncString[0] = tempString[0];
		truncString[1] = tempString[1];
		mapEntry[0] = atoi(truncString);
		mapEntry [1] = atoi(tempString);
		if(hashMap[mapEntry[0]] == NULL){
			hashMap[mapEntry[0]] = mapEntry;
		}else{
			printf("collision at %d\n", mapEntry[0]);
			collisions++;
		}
	}
	printf("\nTotal number of collisions: %d", collisions);
	fclose(inputFile);
	
}