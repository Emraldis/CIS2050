#include "binTree.h"

Branch * createBranch(void * data){
	Branch * newBranch;
	
	newBranch = malloc(sizeof(Branch));
	
	newBranch->leftBranch = NULL;
	newBranch->rightBranch = NULL;
	newBranch->data = data;
	
	return(newBranch);
}

Branch * addBranch(Branch * root, Branch * toBeAdded,int (* compare) (void const *, void const *)){
	Branch * currentBranch;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	printf("\nTEST");
	getchar();
	if(compare == NULL){
		printf("\nERROR");
		exit(0);
	}
	while(currentBranch != NULL){
		switch(compare(currentBranch->data,toBeAdded->data)){
			case -1:
				printf("\nCase -1");
				getchar();
				if(currentBranch->leftBranch == NULL){
					currentBranch->leftBranch = toBeAdded;
					return(root);
				}
				currentBranch = currentBranch->leftBranch;
				break;
			case 0:
				printf("\nCase 0");
				getchar();
				printf("\nData already exists within the tree");
				return(root);
			case 1:
				printf("\nCase 1");
				getchar();
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
	if (currentBranch == NULL){
		printf("\nCurrent Branch is NULL");
		getchar();
	}
	
	return(toBeAdded);
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