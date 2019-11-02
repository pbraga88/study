CFLAGS=-O2
	
INC=include

inverso: main.o inverso.o
	gcc $(CFLAGS) -o inverso main.o inverso.o

main.o: src/main.c
	gcc $(CFLAGS) -I $(INC) -c src/main.c

inverso.o: src/inverso.c
	gcc $(CFLAGS) -DNDEBUG=1 -I $(INC) -c src/inverso.c

clean:
	rm -f *.o inverso
