main : main.o
	gcc -o main -L../lib main.o -llibrary
main.o : main.c
	gcc -c main.c -o main.o -I../include
clean :
	rm *.o $(main)
	rm -rf main

