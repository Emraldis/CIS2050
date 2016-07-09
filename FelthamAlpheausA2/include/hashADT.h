#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include "list.h"

typedef struct HashTableEntry{
	int hashKey;
	struct ListElement * subList;
}HashEntry;

HashEntry * createHashEntry(int keyBase, void * element, Element * table, int tableSize, int dataSize);

int newHashKey(int keyBase, int tableSize);

HashEntry * keyExists(int key, Element * table);

HashEntry * addToSubList(HashEntry * entry, void * element, int size);

int subListSize(HashEntry * entry);


#endif