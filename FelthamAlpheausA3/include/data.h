#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Alpheaus Feltham, 0903594*/

typedef struct FileData{
	char * fileName;
}File;

typedef struct localFileStorage{
	char * folderName;
	struct FileData * * localFiles;
}FileStorage;

/*Creates a File struct
precondition: none
postcondition: Must output a valid File struct
*/
File * createFile(char * path, char * name);

/*Creates a Folder Struct
precondition: none
postcondition: Must output a valid Folder Struct
*/
FileStorage * createStore(char * path, char * name);

/*gets the path of a folder
precondition: Must have a valid folder
postcondition: Must output a valid path string
*/
char * getPath(FileStorage * location);

/*Prints the data of a File struct
precondition: Must have a valid File struct
postcondition: Must properly print the data
*/
void printFileData(File * item);

/*Deletes a file struct
precondition: Must have a valid File struct
postcondition: Must output a valid Branch
*/
void deleteFile(File * item);

/*Renames a file
precondition: Must have a valid File struct
postcondition: Must properly rename the file
*/
File * renameFile(File * item);

/*Deletes a Folder struct
precondition: Must have a valid Folder struct
postcondition: Must properly delete the Folder struct
*/
void deleteFileStorage(FileStorage * location);

/*Prints all the File data of the stored File structs
precondition: must have a proper Folder struct
postcondition: Must properly print out the local File data
*/
void printStoredFiles(FileStorage * location);

#endif