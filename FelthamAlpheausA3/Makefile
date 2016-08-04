all:
	gcc src/main.c src/hashADT.c src/list.c src/directory.c -Wall -pedantic -std=c99 -Iinclude -o bin/runme
	gcc src/testFile.c src/hashADT.c src/list.c src/directory.c -Wall -pedantic -std=c99 -Iinclude -o bin/test
generator:
	gcc src/phoneNumberGenerator.c -Wall -pedantic -std=c99 -o bin/generator