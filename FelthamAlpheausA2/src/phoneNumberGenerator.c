#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char * nameGen (FILE * nameFile);

int main (void){
	FILE * outputFile;
	FILE * nameFile;
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
	nameFile = fopen("NameList.txt","r");
	if((outputFile == NULL) || (nameFile == NULL)){
		printf("\nERROR OPENING FILES");
		exit(0);
	}else{
		printf("\nBeginning name generation");
		getchar();
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
		getchar();
		strcat(tempString,"|");
		name = nameGen(nameFile);
		printf("\nName generated: %s \nPrinting data to file",name);
		getchar();
		strcat(tempString,name);
		strcat(tempString,"\n");
		fputs(tempString,outputFile);
	}
	fclose(nameFile);
	fclose(outputFile);
	return(0);
}

char * nameGen(FILE * nameFile){
	time_t t;
	srand((unsigned)time(&t));
	char * outputName;
	char * nameList;
	char * firstName;
	char * lastName;
	int randInt;
	int i;
	
	outputName = malloc(sizeof(char) * 256);
	nameList = malloc(sizeof(char) * 4096);
	firstName = malloc(sizeof(char) * 64);
	lastName = malloc(sizeof(char) * 64);
	
	fgets(nameList,4096,nameFile);
	randInt = (rand() % 92);
	firstName = strtok(nameList," ");
	for(i=0;i<randInt;i++){
		firstName = strtok(nameList," ");
	}
	strcpy(outputName,firstName);
	strcat(outputName, " ");
	fgets(nameList,4096,nameFile);
	randInt = (rand() % 83);
	lastName = strtok(nameList," ");
	for(i=0;i<randInt;i++){
		lastName = strtok(nameList," ");
	}
	strcpy(outputName,lastName);
	return(outputName);
}