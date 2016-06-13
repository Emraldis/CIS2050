test:
	gcc src/test.c src/list.c src/stackADT.c src/testData.c -Wall -pedantic -std=c99 -Iinclude -o bin/test
maze:
	gcc src/maze.c src/list.c src/stackADT.c src/mazeData.c -Wall -pedantic -std=c99 -Iinclude -o bin/maze
all:
	gcc src/test.c src/list.c src/stackADT.c src/testData.c -Wall -pedantic -std=c99 -Iinclude -o bin/test
	gcc src/maze.c src/list.c src/stackADT.c src/mazeData.c -Wall -pedantic -std=c99 -Iinclude -o bin/maze
debug:
	gcc -g src/maze.c src/list.c src/stackADT.c src/mazeData.c -Wall -pedantic -std=c99 -Iinclude -o bin/debug