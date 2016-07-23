#ifndef _AFELTHAM_HEADERH_HASH
#define _AFELTHAM_HEADERH_HASH
#include <stdlib.h>
#include <stdio.h>

/*Alpheaus Feltham, 0903594*/

typedef struct BranchInfo{
	struct BranchInfo * leftBranch;
	struct BranchInfo * rightBranch;
	void * data;
}Branch;

/*Creates a Branch
precondition: none
postcondition: Must output a valid Branch
*/
Branch * createBranch(void * data);

/*Adds a Branch to the Tree
precondition: Must have a valid Branch to be added, and a proper compare function
postcondition: Must return a root branch, with the new branch added in the right spot
*/
Branch * addBranch(Branch * root, Branch * toBeAdded,int (* compare) (void const *, void const *));

/*Traverses the tree, running a function at each branch, if available
precondition: Must have a valid tree
postcondition: Must correctly visit each branch, and, if applicable, correctly run the given function.
*/
void traverseTree (Branch * root, void (* run) (void const *),int depth, int bool);

/*Deletes the tree
precondition: none
postcondition: Must have a properly deleted tree, with all the contents freed and removed.
*/
void deleteTree (Branch * root, void (* deleteData) (void const *));

#endif