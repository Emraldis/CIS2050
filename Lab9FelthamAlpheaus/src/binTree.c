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
	int comp;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	if (currentBranch == NULL){
		printf("\nCurrent Branch is NULL");
		return(toBeAdded);
	}
	if(compare == NULL){
		printf("\nERROR");
		exit(0);
	}
	while(currentBranch != NULL){
		printf("\nComparing with current Branch");
		comp = compare(currentBranch->data,toBeAdded->data);
		printf("\nComparisson made");
		switch(comp){
			case -1:
				printf("\nCase -1");
				if(currentBranch->leftBranch == NULL){
					currentBranch->leftBranch = toBeAdded;
					printf("\nAdded value");
					return(root);
				}
				currentBranch = currentBranch->leftBranch;
				break;
			case 0:
				printf("\nCase 0");
				printf("\nData already exists within the tree");
				return(root);
			case 1:
				printf("\nCase 1");
				if(currentBranch->rightBranch == NULL){
					currentBranch->rightBranch = toBeAdded;
					printf("\nAdded value");
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
		printf("\nCENTRE");
		if(run != NULL){
			run(currentBranch->data);
		}
		printf("\nLEFT");
		traverseTree(currentBranch->leftBranch,run);
		printf("\nRIGHT");
		traverseTree(currentBranch->rightBranch,run);
	}else{
		printf("\nEMPTY");
	}
}

void deleteTree (Branch * root, void (* deleteData) (void const *)){
	traverseTree(root,deleteData);
}