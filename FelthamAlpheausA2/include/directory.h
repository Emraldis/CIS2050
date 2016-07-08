#ifndef _AFELTHAM_HEADERH
#define _AFELTHAM_HEADERH
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashADT.h"

typedef struct DirectoryEntry{
	char * Fistname;
	char * lastName;
	int phoneNum;
}DirEntry;

DirEntry * newEntry(char * input);

void printTableEntry(HashEntry * entry);

#endif