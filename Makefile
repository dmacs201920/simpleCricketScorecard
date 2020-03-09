score: main.o functions.o
	gcc -o score main.o functions.o
main.o: main.c header.h
	gcc -c -g main.c
functions.o: functions.c header.h
	gcc -c -g functions.c

clean: 
	rm -f *.s *.o a.out score *.c~ *.h~
