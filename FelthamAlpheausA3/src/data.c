#include "data.h"

File * createFile(char * path, char * name){
	File * newFile;
	
	newFile = malloc(sizeof(File));
	newFile->fileName = malloc(sizeof(char) * 768);
	
	strcpy(newFile->fileName,path);
	strcat(newFile->fileName,name);
	
	return(newFile);
}

FileStorage * createStore(char * path, char * name){
	FileStorage * newStorage;
	
	return(newStorage);
}

char * getPath(FileStorage * location){
	char * output;
	
	return(output);
}

void setPath(File * item){
	
}

void printFileData(File * item){
	
}

void deleteFile(File * item){
	
}

File * renameFile(File * item){
	return(NULL);
}

void deleteFileStorage(FileStorage * location){
	
}

void printStoredFiles(FileStorage * location){
	
}