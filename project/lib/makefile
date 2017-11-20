liblibrary.a : calendar.o menstruation.o input.o anniversary.o
	ar rv liblibrary.a calendar.o menstruation.o input.o

calendar.o : calendar.c
	gcc -c -I../include calendar.c -o calendar.o

menstruation.o : menstruation.c
	gcc -c -I../include menstruation.c -o menstruation.o

input.o : input.c
	gcc -c -I../include input.c -o input.o

anniversary.o : anniversary.c
	gcc -c -I../include anniversary.c -o anniversary.o
