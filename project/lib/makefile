liblibrary.a : calendar.o menstruation.o input.o anniversary.o login.o
	ar rv liblibrary.a calendar.o menstruation.o input.o login.o

calendar.o : calendar.c
	gcc -c -I../include calendar.c -o calendar.o

menstruation.o : menstruation.c
	gcc -c -I../include menstruation.c -o menstruation.o

input.o : input.c
	gcc -c -I../include input.c -o input.o

anniversary.o : anniversary.c
	gcc -c -I../include anniversary.c -o anniversary.o

login.o : login.c
	gcc -c -I../include login.c -o login.o

