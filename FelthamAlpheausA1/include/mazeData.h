#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Alpheaus Feltham, 0903594*/

typedef struct PathStruct{
	char choice;
	char * available;
	char * used;
}Path;
/*Creates a new test struct
precondition: none
postcondition: Must output a valid struct with the correct stored data.
*/
Path * create(char * value);
/*Deletes a struct and frees the memory
precondition: Must have a struct to free and delete
postcondition: Must properly free and delete the struct
*/
void deleteStruct(Path * path);
/*Scans the area around the current position in the maze for available routes
precondition: must have a maze, and a position therein.
postcondition: Must return a list of available positions.
*/
char * getOptions(char * * maze, int posX, int posY);