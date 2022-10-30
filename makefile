CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-Wall -ansi
EXEC=main 
all: $(EXEC)

main: main.o piles.o files.o
	$(CC) -o $@ $^$(LDFLAGS)

main.o: main.c
	$(CC) -c $^$(CFLAGS)

piles.o: piles.h piles.c
	$(CC) -c $^$(CFLAGS)

files.o: files.h files.c
	$(CC) -c $^$(CFLAGS)

clean:
	rm -rf *.o
        rm -rf *.o$(EXEC)