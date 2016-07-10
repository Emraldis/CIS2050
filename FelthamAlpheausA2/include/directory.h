#ifndef _AFELTHAM_HEADERH_DIR
#define _AFELTHAM_HEADERH_DIR
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashADT.h"

/*Alpheaus Feltham, 0903594*/

typedef struct DirectoryEntry{
	char * firstName;
	char * lastName;
	double phoneNum;
}DirEntry;
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
DirEntry * newEntry(char * input);
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
void printTableEntry(HashEntry * entry);
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
void printDir(DirEntry * directory);
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
double decode(char * phoneNum);
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
double pwr(int base, int exponent);
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
Element * addToNameList(FILE * inputFile, Element * nameList);
/*Creates a new List element
precondition: none
postcondition: Must output a valid list element with the correct value stored
*/
Element * addToHashTable(Element * hashTable,DirEntry * entry, int dirSize);

#endif