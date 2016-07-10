#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include "list.h"

/*Alpheaus Feltham, 0903594*/

typedef struct HashTableEntry{
	int hashKey;
	struct ListElement * subList;
}HashEntry;

/*This Hash ADT interacts heavily with a linked list ADT, as it uses the separate chaining method for collision resolution. This also allows for easier searching.*/

/*Creates a new Hash Entry
precondition: none
postcondition: Must output a valid Hash Enty with the correct values and subList stored, or return NULL if an entry was simply added to the sublist.
*/
HashEntry * createHashEntry(double keyBase, void * element, Element * table, int tableSize, int dataSize);
/*Creates a new Hash Key
precondition: Must have a base value (preferrably a double, to allow for large numbers), as well as an estimate as to how big the hash table will be.
postcondition: Must output a valid integer key.
*/
int newHashKey(double keyBase, int tableSize);
/*Checks to see if a key already exists
precondition: Must have a valid table to search.
postcondition: Must return either the pre-existing Hash Entry that matches the given key, or NULL if none is found
*/
HashEntry * keyExists(int key, Element * table);
/*Checks the size of the sublist of a Hash Entry
precondition: Must have a valid Entry to measure
postcondition: Must return a valid integer that matches the size of the entry
*/
int subListSize(HashEntry * entry);
/*Deletes a Hash Entry
precondition: Must have a valid entry to delete
postcondition: Must properly delete the sublist and free the Hash Entry
*/
HashEntry * deleteHash(HashEntry * entry);

#endif