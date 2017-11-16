liblibrary.a : calendar.o menstruation.o
	ar rv liblibrary.a calendar.o menstruation.o
calendar.o : calendar.c
	gcc -c -I../include calendar.c -o calendar.o
menstruation.o : menstruation.c
	gcc -c -I../include menstruation.c -o menstruation.o
