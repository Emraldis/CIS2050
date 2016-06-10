#include <stdio.h>

typedef struct PathStruct{
	char choice;
	char * available;
	char * used;
}Path
/*Creates a new test struct
precondition: none
postcondition: Must output a valid struct with the correct stored data.
*/
Test * create(char * value);
/*Deletes a struct and frees the memory
precondition: Must have a struct to free and delete
postcondition: Must properly free and delete the struct
*/
void deleteStruct(Test * struct);