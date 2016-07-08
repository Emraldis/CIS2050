#include "directory.h"

DirEntry * newEntry(char * input){
	DirEntry * newDir;
	char * tempString;
	
	printf("\nCreating new Entry with: %s",input);
	
	newDir = malloc(sizeof(DirEntry));
	newDir->firstName = malloc(sizeof(char) * 32);
	newDir->lastName = malloc(sizeof(char) * 32);
	tempString = malloc(sizeof(char) * 16);
	
	strcpy(newDir->firstName,strtok(input,","));
	strcpy(newDir->lastName,strtok(NULL,","));
	tempString = strtok(NULL,"\n");
	newDir->phoneNum = decode(tempString);
	printf("\nNew Directory entry created:\n\tFirstName: %s\n\tLastName: %s\n\tPhone Number: %f\n",newDir->firstName,newDir->lastName,newDir->phoneNum);
	
	return(newDir);
}

void printTableEntry(HashEntry * entry){
	Element * tempElement;
	DirEntry * tempDir;
	
	tempElement = malloc(sizeof(Element));
	tempDir = malloc(sizeof(DirEntry));
	tempDir->firstName = malloc(sizeof(char) * 32);
	tempDir->lastName = malloc(sizeof(char) * 32);
	
	tempElement = entry->subList;
	
	printf("\nFor Hash Key %d:",entry->hashKey);
	
	while(tempElement != NULL){
		tempDir = tempElement->structPtr;
		printDir(tempDir);
		tempElement = tempElement->next;
	}
	
}

void printDir(DirEntry * directory){
	if(directory == NULL){
		printf("\nEMPTY DIRECTORY");
	}else{
		printf("\n\tFirstName: %s\n\tLastName: %s\n\tPhone Number: %f",directory->firstName,directory->lastName,directory->phoneNum);
	}
}

double decode(char * phoneNum){
	double output = 0;
	int i;
	int j = 0;
	
	for(i=(strlen(phoneNum));i>0;i--){
		switch(phoneNum[j]){
			case '0':
				output = (output + 0);
				break;
			case '1':
				output = (output + (1 * pwr(10,i)));
				break;
			case '2':
				output = (output + (2 * pwr(10,i)));
				break;
			case '3':
				output = (output + (3 * pwr(10,i)));
				break;
			case '4':
				output = (output + (4 * pwr(10,i)));
				break;
			case '5':
				output = (output + (5 * pwr(10,i)));
				break;
			case '6':
				output = (output + (6 * pwr(10,i)));
				break;
			case '7':
				output = (output + (7 * pwr(10,i)));
				break;
			case '8':
				output = (output + (8 * pwr(10,i)));
				break;
			case '9':
				output = (output + (9 * pwr(10,i)));
				break;
			default:
			printf("\nERROR DECODING");
				exit(1);
		}
		j++;
	}
	
	return(output);
}

double pwr(int base, int exponent){
	int i;
	double output = 0;
	
	output = base;
	
	for(i=0;i<exponent;i++){
		output = (output * base);
	}

	
	return(output);
}