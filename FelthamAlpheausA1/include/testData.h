#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Alpheaus Feltham, 0903594*/

typedef struct TestStruct{
	char * value;
}Test;
/*Creates a new test struct
precondition: none
postcondition: Must output a valid struct with the correct stored data.
*/
Test * create(char * value);
/*Deletes a struct and frees the memory
precondition: Must have a struct to free and delete
postcondition: Must properly free and delete the struct
*/
void deleteStruct(Test * input);
/*Prints the value of the struct given
precondition: Must have a struct to read from
postcondition: Must properly print the stored value
*/
void printData(Test * input);