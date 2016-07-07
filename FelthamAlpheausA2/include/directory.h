#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct directoryEntry{
	char * name;
	int phoneNum;
	int hashNum;
}dirEntry;

dirEntry * newEntry(char * input);

int * hashEntry(int number);

dirEntry * findEntry(Element * list, int hashEntry);



