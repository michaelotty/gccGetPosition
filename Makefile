position: main.o libgccGetPosition.a
	gcc -Wall -O3 main.o -lm -lwiringPi -L. -lgccGetPosition -o position

main.o: main.c
	gcc -Wall -O3 -o main.o -c main.c

libgccGetPosition.a:
	make -f gccGetPosition_rtw.mk
.PHONY: clean

clean:
	rm -f *.o *.a position
