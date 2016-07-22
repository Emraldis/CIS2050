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
		comp = compare(currentBranch->data,toBeAdded->data);
		switch(comp){
			case -1:
				printf("\nLEFT");
				if(currentBranch->leftBranch == NULL){
					currentBranch->leftBranch = toBeAdded;
					printf("\nAdded value");
					return(root);
				}
				currentBranch = currentBranch->leftBranch;
				break;
			case 0:
				printf("\nCENTRE");
				printf("\nData already exists within the tree");
				return(root);
			case 1:
				printf("\nRIGHT");
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

void traverseTree (Branch * root, void (* run) (void const *),int depth){
	Branch * currentBranch;
	int i;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	
	if(currentBranch != NULL){
		if(run != NULL){
			depth++;
			if(run != NULL){
				for(i=0;i<depth;i++){
					printf("\t");
				}
			}
		}
		traverseTree(currentBranch->rightBranch,run,depth);
		if(run != NULL){
			printf("\n");
			depth--;
			if(run != NULL){
				for(i=0;i<depth;i++){
					printf("\t");
				}
			}
			run(currentBranch->data);
		}
		if(run != NULL){
			depth++;
			printf("\n");
			if(run != NULL){
				for(i=0;i<depth;i++){
					printf("\t");
				}
			}
		}
		traverseTree(currentBranch->leftBranch,run,depth);
	}else{
		printf("EMPTY");
	}
}

void deleteTree (Branch * root, void (* deleteData) (void const *)){
	traverseTree(root,deleteData,0);
}