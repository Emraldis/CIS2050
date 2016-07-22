#include "binTree.h"

Branch * createBranch(void * data){
	Branch * newBranch;
	
	newBranch = malloc(sizeof(Branch));
	
	newBranch->leftBranch = NULL;
	newBranch->rightBranch = NULL;
	newBranch->data = data;
	
	return(newBranch);
}

Branch * addBranch(Branch * root, Branch * toBeAdded,int (* compare) (void * data, void * data)){
	Branch * currentBranch;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	printf("\nTEST");
	getchar();
	if(compare != NULL){
		printf("\nERROR");
		exit(0);
	}
	while(currentBranch != NULL){
		switch(compare(currentBranch->data,toBeAdded->data)){
			case -1:
				if(currentBranch->leftBranch == NULL){
					currentBranch->leftBranch = toBeAdded;
					return(root);
				}
				currentBranch = currentBranch->leftBranch;
				break;
			case 0:
				printf("\nData already exists within the tree");
				return(root);
			case 1:
				if(currentBranch->rightBranch == NULL){
					currentBranch->rightBranch = toBeAdded;
					return(root);
				}
				currentBranch = currentBranch->rightBranch;
				break;
			default:
				printf("\nERROR");
				exit(0);
		}
	}
	
	return(root);
}

void traverseTree (Branch * root, void (* run) (void const *)){
	Branch * currentBranch;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	
	if(currentBranch != NULL){
		traverseTree(currentBranch->leftBranch,run);
		if(run != NULL){
			run(currentBranch->data);
		}
		traverseTree(currentBranch->rightBranch,run);
	}
}

void deleteTree (Branch * root, void (* deleteData) (void const *)){
	traverseTree(root,deleteData);
}