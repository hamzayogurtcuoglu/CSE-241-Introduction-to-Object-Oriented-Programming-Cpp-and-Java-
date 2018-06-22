all: hello

hello: main.o
	g++ main.o  searchSort.o catalogOperation.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp catalogOperation.cpp searchSort.cpp

clean:
	rm *.o exe

run:
	./exe
