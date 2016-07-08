#ifndef _AFELTHAM_HEADERH_DIR
#define _AFELTHAM_HEADERH_DIR
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashADT.h"

typedef struct DirectoryEntry{
	char * firstName;
	char * lastName;
	int phoneNum;
}DirEntry;

DirEntry * newEntry(char * input);

void printTableEntry(HashEntry * entry);

void printDir(DirEntry * directory);

int decode(char * phoneNum);

int pwr(int base, int exponent);

#endif