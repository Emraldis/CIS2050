#include "binTree.h"

/*Alpheaus Feltham, 0903594*/

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
				if(currentBranch->leftBranch == NULL){
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

void traverseTree (Branch * root, void (* run) (void const *),int depth, int bool){
	Branch * currentBranch;
	int i;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	if(currentBranch != NULL){
		traverseTree(currentBranch->rightBranch,run,(depth + 1),bool);
		if(bool == 1){
			printf("\n");
		}
		if(run != NULL){
			for(i=-1;i<depth;i++){
				printf("\t");
			}
		}
		if(bool == 1){
			printf("/");
		}
	}
	if(run != NULL){
		if(bool == 1){
			printf("\n");
		}
		if(run != NULL){
			for(i=0;i<depth;i++){
				printf("\t");
			}
		}
		if(bool == 1){
			printf("-");
		}
		if(currentBranch != NULL){
			run(currentBranch->data);
		}else{
			run(NULL);
		}
	}
	if(currentBranch != NULL){
		if(bool == 1){
			printf("\n");
		}
		if(run != NULL){
			for(i=-1;i<depth;i++){
				printf("\t");
			}
		}
		if(bool == 1){
			printf("\\");
		}
		traverseTree(currentBranch->leftBranch,run,(depth + 1),bool);
	}
}

void deleteTree (Branch * root, void (* deleteData) (void const *)){
	traverseTree(root,deleteData,0,0);
}

Branch * rotateRight(Branch * toRotate){
	Branch * tempBranch;
	
	tempBranch = malloc(sizeof(Branch));
	if((toRotate->leftBranch->rightBranch == NULL) && (toRotate->leftBranch->leftBranch != NULL)){
		tempBranch = toRotate;
		toRotate = toRotate->leftBranch;
		toRotate->rightBranch = tempBranch;
	}else if((toRotate->leftBranch->leftBranch == NULL) && (toRotate->leftBranch->rightBranch != NULL)){
		tempBranch = toRotate;
		toRotate = toRotate->leftBranch;
		toRotate->rightBranch->rightBranch = tempBranch;
	}
	return(toRotate);
}

Branch * rotateLeft(Branch * toRotate){
	Branch * tempBranch;
	
	tempBranch = malloc(sizeof(Branch));
	if((toRotate->rightBranch->leftBranch == NULL) && (toRotate->rightBranch->rightBranch != NULL)){
		tempBranch = toRotate;
		toRotate = toRotate->rightBranch;
		toRotate->leftBranch = tempBranch;
	}else if((toRotate->rightBranch->rightBranch == NULL) && (toRotate->rightBranch->leftBranch != NULL)){
		tempBranch = toRotate;
		toRotate = toRotate->rightBranch;
		toRotate->leftBranch->leftBranch = tempBranch;
	}
	return(toRotate);
}

Branch * balanceBranch(Branch * toBalance){
	Branch * tempBranch;
	
	tempBranch = malloc(sizeof(Branch));
	while(isBalanced(toBalance) != 0){
		switch(isBalanced(toBalance)){
			case -1:
				printf("\nSkewed Left");
				getchar();
				tempBranch = rotateRight(toBalance);
				break;
			case 0:
				printf("\nBalanced");
				getchar();
				break;
			case 1:
				printf("\nSkewed Right");
				getchar();
				tempBranch = rotateLeft(toBalance);
				break;
			default:
				printf("\nERROR");
				exit(0);
		}
	}
	return(tempBranch);
}

int isBalanced(Branch * testBranch){
	if(testBranch->leftBranch != NULL){
		if((testBranch->rightBranch == NULL) && (((testBranch->leftBranch->rightBranch != NULL) && (testBranch->leftBranch->leftBranch == NULL)) || ((testBranch->leftBranch->leftBranch != NULL) && (testBranch->leftBranch->rightBranch == NULL)))){
			return(-1);
		}
	}else if(testBranch->rightBranch != NULL){
		if((testBranch->leftBranch == NULL) && (((testBranch->rightBranch->rightBranch != NULL) && (testBranch->rightBranch->leftBranch == NULL)) || ((testBranch->rightBranch->leftBranch != NULL) && (testBranch->rightBranch->rightBranch == NULL)))){
			return(1);
		}
	}
	return(0);
}

Branch * balanceTree(Branch * root){
	Branch * currentBranch;
	
	currentBranch = malloc(sizeof(Branch));
	
	currentBranch = root;
	
	if(currentBranch != NULL){
		currentBranch = balanceTree(currentBranch->leftBranch);
		currentBranch = balanceBranch(currentBranch);
		currentBranch = balanceTree(currentBranch->rightBranch);
	}
	return(root);
}