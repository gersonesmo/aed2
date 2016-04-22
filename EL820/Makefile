a.out: main.o EnteroLargo.o EL820.o
	g++ -Wall -std=c++11 main.o EnteroLargo.o EL820.o
main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp
EL820.o: EL820.cpp EL820.h EnteroLargo.o
	g++ -Wall -std=c++11 -c EL820.cpp
EnteroLargo.o: EnteroLargo.cpp EnteroLargo.h
	g++ -Wall -std=c++11 -c EnteroLargo.cpp
clean:
	rm *.o *.out *.txt experimenta validacion
	
experimenta: experimenta.o EnteroLargo.o EL820.o
	g++ -Wall -std=c++11 -o experimenta experimenta.o EnteroLargo.o EL820.o

experimenta.o: experimenta.cpp
	g++ -Wall -std=c++11 -c experimenta.cpp

validacion: validacion.o EnteroLargo.o EL820.o
	g++ -Wall -std=c++11 -o validacion validacion.o EnteroLargo.o EL820.o
	
validacion.o: validacion.cpp
	g++ -Wall -std=c++11 -c validacion.cpp
