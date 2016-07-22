#include "binTree.h"

Branch * createBranch(void * data){
	Branch * newBranch;
	
	newBranch = malloc(sizeof(Branch));
	
	newBranch->leftBranch = NULL;
	newBranch->rightBranch = NULL;
	newBranch->data = data;
	
	return(newBranch);
}

Branch * addBranch(Branch * root, Branch * toBeAdded,int (* compare) (void * data1, void * data2)){
	Branch * currentBranch;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
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

void * traverseTree (Branch * root, void * searchData,int (* compare) (void * data1, void * data2), void (* run) (void * data)){
	
}

void * removeBranch (Branch * root, void * searchData, int (* compare) (void * data1, void * data2), void (* deleteData) (void * data)){
	
}

void * deleteTree (Branch * root, void (* deleteData) (void * data)){
	
}