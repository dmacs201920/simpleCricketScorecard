		# WRITTEN BY: RAMU.V
		# REGD.NO:    173230

score: main.o functions.o	
	gcc -o score main.o functions.c
main.o: main.c header.h
	gcc -c -g main.c
functions.o: functions.c header.h
	gcc -c -g functions.c display.c

clean: 
	rm -f *.s *.o a.out score *.c~ *.h~
