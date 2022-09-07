all: test_set

test_set: test_set.cpp set.cpp set.h
	g++ -std=c++11 test_set.cpp set.cpp -o test

clean:
	rm -f all *.o