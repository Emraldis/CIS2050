#include <time.h>
#include "binTree.h"
#include "testData.h"

int main(void){
	time_t t;
	int random;
	int i = 0;
	int limit;
	srand((unsigned)time(&t));

	Branch * searchBranch;
	Branch * testTree = NULL;
	
	searchBranch = malloc(sizeof(Branch));
	limit = (rand() % 200);
	while(i < limit){
		random = (rand() % 101);
		testTree = addBranch(testTree,createBranch(createData(random)),compareData);
		printf("\nCreated data with value: %d",random);
		i++;
	}
	printf("\nTree Created, size %d",limit);
	getchar();
	traverseTree(testTree,printData,0,1);
	printf("\nSearching for values");
	getchar();
	i = 0;
	while(i < 10){
		random = (rand() % 101);
		printf("\nSearching for %d\n",random);
		searchBranch = findBranch(compareData,testTree,createData(random));
		if(searchBranch != NULL){
			runFunc(searchBranch,printData);
		}else{
			printf("\nValue does not exist within tree");
		}
		i++;
	}
	printf("\nDeleting Tree");
	getchar();
	deleteTree(testTree,deleteData);
	printf("\nTree Deleted, attempting a search in an empty tree");
	getchar();
	traverseTree(testTree,printData,0,1);
	searchBranch = findBranch(compareData,testTree,createData(999));
	runFunc(searchBranch,printData);
	printf("\nIf the program has gotten this far without segfaulting, it should work without issue.\n");
	
	return(0);
}