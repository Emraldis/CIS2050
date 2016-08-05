#include "binTree.h"

/*Alpheaus Feltham, 0903594*/

Branch * createBranch(void * data){
	Branch * newBranch;
	
	newBranch = malloc(sizeof(Branch));
	
	newBranch->leftBranch = NULL;
	newBranch->rightBranch = NULL;
	newBranch->data = data;
	newBranch->parent = NULL;
	
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
				if(currentBranch->leftBranch == NULL){
					toBeAdded->parent = currentBranch;
					currentBranch->leftBranch = toBeAdded;
					printf("\nAdded value");
					return(root);
				}
				currentBranch = currentBranch->leftBranch;
				break;
			case 0:
				printf("\nData already exists within the tree");
				return(root);
			case 1:
				if(currentBranch->rightBranch == NULL){
					toBeAdded->parent = currentBranch;
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

void traverseTree (Branch * root, void (* run) (void const *),int depth, int mode){
	Branch * currentBranch;
	int i;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	if(currentBranch != NULL){
		traverseTree(currentBranch->rightBranch,run,(depth + 1),mode);
		if(mode == 1){
			printf("\n");
		}
		if(run != NULL){
			for(i=-1;i<depth;i++){
				printf("\t");
			}
		}
		if(mode == 1){
			printf("/");
		}
	}
	if(run != NULL){
		if(mode == 1){
			printf("\n");
		}
		if(run != NULL){
			for(i=0;i<depth;i++){
				printf("\t");
			}
		}
		if(mode == 1){
			printf("-");
		}
		if(currentBranch != NULL){
			run(currentBranch->data);
			if(mode == 2){
				free(currentBranch->leftBranch);
				free(currentBranch->rightBranch);
				currentBranch = NULL;
			}
		}else{
			run(NULL);
		}
	}
	if(currentBranch != NULL){
		if(mode == 1){
			printf("\n");
		}
		if(run != NULL){
			for(i=-1;i<depth;i++){
				printf("\t");
			}
		}
		if(mode == 1){
			printf("\\");
		}
		traverseTree(currentBranch->leftBranch,run,(depth + 1),mode);
	}
}

void deleteTree (Branch * root, void (* deleteData) (void const *)){
	traverseTree(root,deleteData,0,2);
}

Branch * findBranch (int (*compare) (void const *, void const *), Branch * root, void const * searchData){
	Branch * currentBranch;
	Branch * tempBranch;
	
	currentBranch = malloc(sizeof(Branch));
	tempBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	
	if(currentBranch != NULL){
		tempBranch = findBranch(compare,currentBranch->leftBranch,searchData);
		if(tempBranch != NULL){
			return(tempBranch);
		}
		tempBranch = findBranch(compare,currentBranch->rightBranch,searchData);
		if(tempBranch != NULL){
			return(tempBranch);
		}
		if(compare(currentBranch->data,searchData) == 0){
			return(currentBranch);
		}
	}
	return(NULL);
}

void runFunc(Branch * root, void (* run) (void const *)){
	if(run != NULL){
		run(root->data);
	}
}