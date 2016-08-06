#include <time.h>
#include "binTree.h"
#include "testData.h"

/*Alpheaus Feltham, 0903594*/

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
	traverseTree(testTree,printData,0,1);
	printf("\nSearching for values");
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
	testTree = deleteTree(testTree,deleteData);
	printf("\nTree Deleted, attempting a search in an empty tree");
	searchBranch = findBranch(compareData,testTree,createData(999));
	if(searchBranch == NULL){
		printf("\nNo results");
	}
	printf("\nAttempting to print an empty branch");
	runFunc(searchBranch,printData);
	printf("\nAttempting to print an empty tree");
	traverseTree(testTree,printData,0,1);
	printf("\nIf the program has gotten this far without segfaulting, it should work without issue.\n");
	
	return(0);
}