a.out: main.o EnteroLargo.o
	g++ -std=c++11 main.o EnteroLargo.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
EnteroLargo.o: EnteroLargo.cpp EnteroLargo.h
	g++ -std=c++11 -c EnteroLargo.cpp
clean:
	rm *.o *.out
