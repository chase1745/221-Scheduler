all: run-main

run-main: Hashtable.o main.o
	c++ -std=c++11 -o run-main Hashtable.o main.o

main.o: main.cpp Hashtable.h 
	c++ -std=c++11 -c main.cpp

Hashable.o: Hashtable.h LinkedList.h
	c++ -std=c++11 -c Hashtable.cpp

clean:
	rm *.o run-main