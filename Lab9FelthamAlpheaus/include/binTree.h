#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include <stdlib.h>
#include <stdio.h>

typedef struct BranchInfo{
	struct BranchInfo * leftBranch;
	struct BranchInfo * rightBranch;
	void * data;
}Branch;

Branch * createBranch(void * data);

Branch * addBranch(Branch * root, Branch * toBeAdded,int (* compare) (void const *, void const *));

void traverseTree (Branch * root, void (* run) (void const *));

void deleteTree (Branch * root, void (* deleteData) (void const *));

#endif