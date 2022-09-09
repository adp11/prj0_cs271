# minor changes based on the template provided from Bootcamp C++ pdf
all: test

test: set.o test_set.o
	g++ -std=c++11 set.o test_set.o -o set

test_set.o: set.o test_set.cpp
	g++ -std=c++11 -c test_set.cpp

set.o: set.cpp set.h
	g++ -std=c++11 -c set.cpp

clean:
	rm -f all *.o