#include <stdlib.h>

typedef struct BranchInfo{
	struct Branchinfo * leftBranch;
	struct Branchinfo * rightBranch;
	void * data;
}Branch;

Branch * createBranch(void * data);

Branch * addBranch(Branch * root, Branch * toBeAdded,int (* compare) (void * data1, void * data2));

void * traverseTree (Branch * root, void * searchData,int (* compare) (void * data1, void * data2), void (* run) (void * data));

void * removeBranch (Branch * root, void * searchData, int (* compare) (void * data1, void * data2), void (* deleteData) (void * data));

void * deleteTree (Branch * root, void (* deleteData) (void * data));
