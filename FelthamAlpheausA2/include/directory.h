#ifndef _AFELTHAM_HEADERH_DIR
#define _AFELTHAM_HEADERH_DIR
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashADT.h"

typedef struct DirectoryEntry{
	char * firstName;
	char * lastName;
	long phoneNum;
}DirEntry;

DirEntry * newEntry(char * input);

void printTableEntry(HashEntry * entry);

void printDir(DirEntry * directory);

double decode(char * phoneNum);

double pwr(int base, int exponent);

#endif