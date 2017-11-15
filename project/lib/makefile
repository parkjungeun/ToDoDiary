liblibrary.a : calendar.o textColorSet.o
	ar rv liblibrary.a calendar.o textColorSet.o
calendar.o : calendar.c
	gcc -c -I../include calendar.c -o calendar.o
textColorSet.o : textColorSet.c
	gcc -c -I../include textColorSet.c -o textColorSet.o
