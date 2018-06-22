all: hello

hello: main.o
	g++ main.o SparseVector.o SparseMatrix.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp SparseVector.cpp SparseMatrix.cpp

clean:
	rm *.o exe

run:
	./exe
