#ifndef _AFELTHAM_HEADERH_DIR
#define _AFELTHAM_HEADERH_DIR
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashADT.h"

/*Alpheaus Feltham, 0903594*/

/*This is just a support library, not an ADT*/

typedef struct DirectoryEntry{
	char * firstName;
	char * lastName;
	double phoneNum;
}DirEntry;
/*Creates a new Directory Element
precondition: none
postcondition: Must output a valid Directory Element with the correct values stored
*/
DirEntry * newEntry(char * input);
/*Prints out the directories stored within the Hash Element
precondition: Must have Directories to print
postcondition: none
*/
void printTableEntry(HashEntry * entry);
/*Prints out the values stored within the Directory Element
precondition: Must have values to print
postcondition: none
*/
void printDir(DirEntry * directory);
/*Decodes a Phone number into a double
precondition: must have a valid number stored within the string
postcondition: Must return the input value as a double, correctly decoded
*/
double decode(char * phoneNum);
/*Utility element that does basic exponents
precondition: Must have a valid base and exponent
postcondition: Must return a correct result
*/
double pwr(int base, int exponent);
/*Adds the content of a file to a list
precondition: Must have a valid file to read from, and a valid list to write to
postcondition: Must return a valid list with the new data added to it
*/
Element * addToNameList(FILE * inputFile, Element * nameList);
/*Adds a directory entry to a hash table
precondition: must have a valid hash table and directory entry
postcondition: Must correctly return a list entry that can be added to a hash table list.
*/
Element * addToHashTable(Element * hashTable,DirEntry * entry, int dirSize);

#endif