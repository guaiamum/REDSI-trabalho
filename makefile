allc: clean all

all: main.o Produto.o Camera.o Lente.o
	g++ -o main main.o Produto.o Camera.o Lente.o

main.o: main.cpp
	g++ -c main.cpp

Produto.o: Model/Produto.cpp
	g++ -c Model/Produto.cpp

Camera.o: Model/Camera.cpp
	g++ -c Model/Camera.cpp

Lente.o: Model/Lente.cpp
	g++ -c Model/Lente.cpp

#******************************
#TESTING AND CLEANING
test: Produto.o Camera.o Lente.o
	clear
	g++ -o test test.cpp Produto.o Camera.o Lente.o
	./test

#******************************
# CLEANING CONSOLE AND DIRECTORY
clean:
	clear
	rm -rf *o main

.PHONY: test
