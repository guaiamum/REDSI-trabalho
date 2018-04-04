all: main.o Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o
	g++ -o main main.o Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o

allc: clean all

main.o: main.cpp
	g++ -c main.cpp

Produto.o: Model/Produto.cpp
	g++ -c Model/Produto.cpp

Camera.o: Model/Camera.cpp
	g++ -c Model/Camera.cpp

Lente.o: Model/Lente.cpp
	g++ -c Model/Lente.cpp

Flash.o: Model/Flash.cpp
	g++ -c Model/Flash.cpp

Tripe.o: Model/Tripe.cpp
	g++ -c Model/Tripe.cpp

ProdutoPreco.o: Model/ProdutoPreco.cpp
	g++ -c Model/ProdutoPreco.cpp

#******************************
#TESTING AND CLEANING
test: Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o
	clear
	g++ -o test test.cpp Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o
	./test

#******************************
# CLEANING CONSOLE AND DIRECTORY
clean:
	clear
	rm -rf *o main

.PHONY: test
