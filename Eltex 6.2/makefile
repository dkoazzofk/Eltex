all:
	gcc -fPIC list.c -c
	gcc -shared list.o -o liblist.so
	gcc main.c Person.c -o main -L. .\liblist.so