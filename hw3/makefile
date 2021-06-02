CC=gcc
AR=ar
FLAGS=-Wall -g



all: isort  txtfind

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o


txtfind:txtfind.o
	$(CC) $(FLAGS) -o  txtfind  txtfind.o

	
isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c


txtfind.o: txtfind.c 
	$(CC) $(FLAGS) -c txtfind.c


.PHONY: clean all

clean: 
	rm -f  isort txtfind *.o  *.a  