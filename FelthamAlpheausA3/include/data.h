#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct FileData{
	char * fileName;
}File;

typedef struct localFileStorage{
	char * folderName;
	struct FileData * * localFiles;
}FileStorage;

File * createFile(char * path, char * name);

FileStorage * createStore(char * path, char * name);

char * getPath(FileStorage * location);

char * setPath(File * item);

void printFileData(File * item);

void deleteFile(File * item);

File * renameFile(File * item);

void deleteFileStorage(FileStorage * location);

void printStoredFiles(FileStorage * location);

#endif