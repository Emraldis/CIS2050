#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListData{
	char * value;
	struct ListData * next;
}List;

List * createList(char * value);

List * destroyList();

List * addToFront(List * element, List * list);

char * readFirstValue(List * list);

int getLength(List * list);

void printList(List * list);

List * removeFromFront(List * list);