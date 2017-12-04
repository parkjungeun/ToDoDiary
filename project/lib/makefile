liblibrary.a : calendar.o menstruation.o input.o anniversary.o login.o output.o move.o
	ar rv liblibrary.a calendar.o menstruation.o input.o anniversary.o login.o output.o move.o

calendar.o : calendar.c
	gcc -c -I../include calendar.c -o calendar.o

menstruation.o : menstruation.c
	gcc -c -I../include menstruation.c -o menstruation.o

input.o : input.c
	gcc -c -I../include input.c -o input.o

output.o : output.c
	gcc -c -I../include output.c -o output.o

anniversary.o : anniversary.c
	gcc -c -I../include anniversary.c -o anniversary.o

login.o : login.c
	gcc -c -I../include login.c -o login.o

move.o : move.c
	gcc -c -I../include move.c -o move.o

clean :
	rm *.o $(liblibrary.a)
