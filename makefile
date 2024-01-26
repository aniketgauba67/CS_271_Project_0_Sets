test: main.o
	g++ -o test main.o

main.o: test_set.cpp set.h set.cpp 
		g++ -c test_set.cpp
