#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashADT.h"

typedef struct directoryEntry{
	char * Fistname;
	char * lastName;
	int phoneNum;
}dirEntry;

dirEntry * newEntry(char * input);

void printTableEntry(HashEntry * entry);