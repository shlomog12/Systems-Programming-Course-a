CC=gcc
AR=ar
FLAGS=-Wall -g


all: maind  mains 

mains: main.o libmyMath.a 
	$(CC) $(FLAGS) -o mains main.o libmyMath.a 

maind: main.o libmyMath.so  
	$(CC) $(FLAGS) -o maind main.o ./libmyMath.so


libmyMath.a:  basicMath.o power.o
	$(AR) -rcs libmyMath.a  basicMath.o power.o


libmyMath.so: basicMath.o power.o
	$(CC) -shared -o libmyMath.so basicMath.o power.o


main.o: main.c myMath.h 
	$(CC) $(FLAGS) -c main.c


power.o: power.c myMath.h
	$(CC) $(FLAGS) -c power.c


basicMath.o: basicMath.c myMath.h
	$(CC) $(FLAGS) -c basicMath.c


.PHONY: clean all

clean: 
	rm -f   mains  maind    *.o   *.so *.a          