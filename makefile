#Define includes
LIB=-L
INC=-Isrc/
SRC= src/linkedlist.h \
     src/logging.h \
     src/logging.c \
     src/main.c

TARGET=linkedlist

# C Make File
CC=gcc

CFLAGS=-c -Wall

all:	$(TARGET)

$(TARGET):
	$(CC) $(FLAGS) $(INC) $(LIB) $(SRC) -o linkedlist

clean:
	rm -rf src/*.o linkedlist
