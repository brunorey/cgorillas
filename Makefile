# the compiler: gcc for C program, define as g++ for C++
CC = gcc
CFLAGS  = -g -Wall

default: cgorillas

all: cgorillas

cgorillas: cgorillas.c banana.o buildings.o gorillas.o landscape.o aux.o
	$(CC) $(CFLAGS) -o cgorillas cgorillas.c banana.o buildings.o gorillas.o landscape.o aux.o -lgraph -lm

banana.o: banana.c banana.h landscape.h
	$(CC) $(CFLAGS) -c banana.c

buildings.o: buildings.c buildings.h aux.h
	$(CC) $(CFLAGS) -c buildings.c

gorillas.o: gorillas.c gorillas.h
	$(CC) $(CFLAGS) -c gorillas.c

landscape.o: landscape.c landscape.h gorillas.h buildings.h aux.h
	$(CC) $(CFLAGS) -c landscape.c

aux.o: aux.c aux.h
	$(CC) $(CFLAGS) -c aux.c

clean:
	$(RM) *.o cgorillas
