#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char * nameGen ();

int main (void){
	FILE * outputFile;
	char * tempString;
	char * tempStringTwo;
	char * name;
	int tempInt;
	int i;
	time_t t;
	srand((unsigned)time(&t));
	
	tempString = malloc(sizeof(char) * 256);
	tempStringTwo = malloc(sizeof(char) * 256);
	name = malloc(sizeof(char) * 256);
	outputFile = fopen("PhoneNumbers.txt","w");
	if(outputFile == NULL){
		printf("\nERROR OPENING FILE");
		exit(0);
	}else{
		printf("\nBeginning name generation");
	}
	for(i=0;i<100;i++){
		sprintf(tempString,"%d",6045);
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
		printf("\nPhone number generated: %s \ngenerating name",tempString);
		strcat(tempString,"|");
		name = nameGen();
		printf("\nName generated: %s \nPrinting data to file",name);
		getchar();
		strcat(tempString,name);
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
	int randInt;
	int i;
	
	outputName = malloc(sizeof(char) * 256);
	firstNameList = malloc(sizeof(char) * 4096);
	lastNameList = malloc(sizeof(char) * 4096);
	tempList = malloc(sizeof(char) * 4096);
	firstName = malloc(sizeof(char) * 64);
	lastName = malloc(sizeof(char) * 64);
	nameFile = fopen("NameList.txt","r");
	
	if(nameFile == NULL){
		printf("\nERROR OPENING FILE");
		exit(0);
	}
	fgets(firstNameList,4096,nameFile);
	fgets(lastNameList,4096,nameFile);
	randInt = (rand() % 92);
	strcpy(tempList,firstNameList);
	firstName = strtok(tempList," ");
	for(i=0;i<randInt;i++){
		firstName = strtok(NULL," ");
	}
	strcpy(outputName,firstName);
	strcat(outputName, " ");
	randInt = (rand() % 83);
	strcpy(tempList,lastNameList);
	lastName = strtok(tempList," ");
	for(i=0;i<randInt;i++){
		lastName = strtok(NULL," ");
	}
	strcat(outputName,lastName);
	fclose(nameFile);
	return(outputName);
}