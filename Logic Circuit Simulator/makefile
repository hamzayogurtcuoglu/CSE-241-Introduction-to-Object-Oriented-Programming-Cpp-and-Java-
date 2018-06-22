all: hello

hello: main.o
	g++ main.o connectionCircuit.o gatesClass.o inputOutputClass.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp connectionCircuit.cpp gatesClass.cpp inputOutputClass.cpp

clean:
	rm *.o exe

run:
	./exe
