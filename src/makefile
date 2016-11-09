#Define includes
LIB=-L
INC=-I

# C Make File
CC=gcc

CFLAGS=-c -Wall

all:	linkedlist

linkedlist: logging.o main.o
	$(CC) $(INC) $(LIB) logging.o main.o -o linkedlist

logging.o: logging.c
	$(CC) $(INC) $(LIB) -c logging.c

main.o: main.c
	$(CC) $(INC) $(LIB) -c main.c

clean:
	rm -rf *.o linkedlist
