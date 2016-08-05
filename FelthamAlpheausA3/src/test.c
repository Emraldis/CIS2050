#include <time.h>
#include "binTree.h"
#include "testData.h"

int main(void){
	time_t t;
	int random;
	int i = 0;
	srand((unsigned)time(&t));

	Branch * searchBranch;
	Branch * testTree = NULL;
	
	searchBranch = malloc(sizeof(Branch));
	
	while(i < 100){
		random = (rand() % 101);
		testTree = addBranch(testTree,createBranch(createData(random)),compareData);
		printf("\nCreated data with value: %d",random);
		i++;
	}
	printf("\nTree Created");
	getchar();
	traverseTree(testTree,printData,0,1);
	printf("\nSearching for values");
	getchar();
	while(i < 10){
		random = (rand() % 101);
		printf("\nSearching for %d",random);
		searchBranch = findBranch(compareData,testTree,createData(random));
		if(searchBranch != NULL){
			runFunc(searchBranch,printData);
		}
		
	}
	
	return(0);
}