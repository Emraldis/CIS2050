all:
	gcc src/main.c src/binTree.c src/data.c -Wall -pedantic -std=c99 -Iinclude -o bin/runme
	gcc src/test.c src/binTree.c src/testData.c -Wall -pedantic -std=c99 -Iinclude -o bin/test
test:
	gcc src/test.c src/binTree.c src/testData.c -Wall -pedantic -std=c99 -Iinclude -o bin/test