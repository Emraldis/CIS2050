#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include "list.h"

typedef struct HashTableEntry{
	int hashKey;
	struct ListElement * subList;
}HashEntry;

HashEntry * createHashEntry(double keyBase, void * element, Element * table, int tableSize, int dataSize);

int newHashKey(double keyBase, int tableSize);

HashEntry * keyExists(int key, Element * table);

int subListSize(HashEntry * entry);

HashEntry * deleteHash(HashEntry * entry);

#endif