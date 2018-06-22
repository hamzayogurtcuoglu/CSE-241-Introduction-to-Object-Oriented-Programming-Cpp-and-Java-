all: hello

hello: main.o
	g++ main.o baseClass.o directoryFilesClass.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp baseClass.cpp directoryFilesClass.cpp 

clean:
	rm *.o exe

run:
	./exe
