#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

char * nameGen ();

int main (int argc char * argv[]){
	FILE * outputFile;
	char * tempString;
	char * tempStringTwo;
	char * name;
	int tempInt;
	int i;
	time_t t;
	srand((unsigned)time(&t));
	int numNames = 100;
	
	tempString = malloc(sizeof(char) * 256);
	tempStringTwo = malloc(sizeof(char) * 256);
	name = malloc(sizeof(char) * 256);
	outputFile = fopen("PhoneNumbers.txt","w");
	
	if(argc > 1){
		numNames = atoi(argv[1]);
	}
	
	if(outputFile == NULL){
		printf("\nERROR OPENING FILE");
		exit(0);
	}else{
		printf("\nBeginning name generation");
	}
	for(i=0;i<numNames;i++){
		name = nameGen();
		printf("\nName generated: %s",name);
		sleep(2);
		strcpy(tempString,name);
		strcat(tempString,",");
		sprintf(tempStringTwo,"%d",6045);
		strcat(tempString,tempStringTwo);
		tempInt = (rand() % 100);
		if(tempInt < 10){
			strcat(tempString,"0");
		}
		sprintf(tempStringTwo,"%d",tempInt);
		strcat(tempString,tempStringTwo);
		tempInt = (rand() % 10000);
		if(tempInt < 999){
			if(tempInt < 99){
				if(tempInt < 9){
					strcat(tempString,"0");
				}
				strcat(tempString,"0");
			}
			strcat(tempString,"0");
		}
		sprintf(tempStringTwo,"%d",tempInt);
		strcat(tempString,tempStringTwo);
		printf("\nPhone number generated: %s",tempString);
		strcat(tempString,"\n");
		fputs(tempString,outputFile);
	}
	fclose(outputFile);
	return(0);
}

char * nameGen(){
	FILE * nameFile;
	time_t t;
	srand((unsigned)time(&t));
	char * outputName;
	char * firstNameList;
	char * lastNameList;
	char * firstName;
	char * lastName;
	char * tempList;
	char * tempString;
	int firstNameLimit;
	int lastNameLimit;
	int randInt;
	int i;
	
	outputName = malloc(sizeof(char) * 256);
	firstNameList = malloc(sizeof(char) * 4096);
	lastNameList = malloc(sizeof(char) * 4096);
	tempList = malloc(sizeof(char) * 4096);
	firstName = malloc(sizeof(char) * 64);
	lastName = malloc(sizeof(char) * 64);
	tempString = malloc(sizeof(char) * 64);
	nameFile = fopen("NameList.txt","r");
	
	
	if(nameFile == NULL){
		printf("\nERROR OPENING FILE");
		exit(0);
	}
	
	fgets(firstNameList,4096,nameFile);
	strcpy(tempList,firstNameList);
	if(tempList != NULL){
		if(strlen(tempList) >=1){
			firstNameLimit = 0;
			tempString = strtok(tempList," ");
			while(strtok(NULL," ") != NULL){
				firstNameLimit++;
			}
		}
	}
	//printf("\n%d First names detected",firstNameLimit);
	fgets(lastNameList,4096,nameFile);
	strcpy(tempList,lastNameList);
	if(tempList != NULL){
		if(strlen(tempList) >=1){
			lastNameLimit = 0;
			tempString = strtok(tempList," ");
			while(strtok(NULL," ") != NULL){
				lastNameLimit++;
			}
		}
	}
	//printf("\n%d Last names detected",lastNameLimit);
	fclose(nameFile);
	
	nameFile = fopen("NameList.txt","r");
	
	if(nameFile == NULL){
		printf("\nERROR OPENING FILE");
		exit(0);
	}
	fgets(firstNameList,4096,nameFile);
	fgets(lastNameList,4096,nameFile);
	randInt = (rand() % firstNameLimit);
	strcpy(tempList,firstNameList);
	firstName = strtok(tempList," ");
	for(i=0;i<randInt;i++){
		firstName = strtok(NULL," ");
	}
	strcpy(outputName,firstName);
	strcat(outputName, ",");
	randInt = (rand() % lastNameLimit);
	strcpy(tempList,lastNameList);
	lastName = strtok(tempList," ");
	for(i=0;i<randInt;i++){
		lastName = strtok(NULL," ");
	}
	strcat(outputName,lastName);
	fclose(nameFile);
	return(outputName);
}