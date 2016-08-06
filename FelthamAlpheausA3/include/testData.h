#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Alpheaus Feltham, 0903594*/

typedef struct DataInfo{
	int data;
}Data;

/*Creates a Data struct
precondition: none
postcondition: Must output a valid Data struct
*/
Data * createData(int input);

/*Compares two Data structs
precondition: Must have two valid Data structs
postcondition: Must output the correct comparisson integer (-1,0,1)
*/
int compareData(void const * dataA,void const * dataB);

/*Deletes a Data struct
precondition: Must have a valid Data struct
postcondition: Must correctly delete the Data struct
*/
void deleteData(void const * input);

/*Prints the data stored within the Data struct
precondition: Must have a valid Data struct
postcondition: Must correctly print the data
*/
void printData(void const * input);
