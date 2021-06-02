CC=gcc
AR=ar
FLAGS=-Wall -g

all: main

main: main.o libmyBank.a
	$(CC) $(FLAGS) -o main main.o libmyBank.a 

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a  myBank.o

main.o: main.c myBank.h myBank.c
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all

clean: 
	rm -f   main  *.o  *.a  