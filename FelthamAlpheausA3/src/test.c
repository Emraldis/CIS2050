#include <time.h>
#include "binTree.h"
#include "testData.h"

int main(void){
	time_t t;
	int random;
	int i;
	srand((unsigned)time(&t));
	
	Branch * testTree = NULL;
	
	while(i < 100){
		random = (rand() % 101);
		testTree = addBranch(testTree,createBranch(createData(random)),compareData);
		printf("\nCreated data with value: %d",random);
	}
	
	traverseTree(testTree,printData,0,1);
	
	return(0);
}