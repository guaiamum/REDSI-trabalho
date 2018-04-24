#COMPILE ALL
all: main.o Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o Generic.o GenericDAO.o CameraDAO.o LenteDAO.o
	g++ -o main -I/usr/local/include -I/usr/local/include/cppconn main.o Generic.o GenericDAO.o Produto.o Camera.o CameraDAO.o Lente.o LenteDAO.o Flash.o Tripe.o ProdutoPreco.o -lmysqlcppconn

#CLEAN AND COMPILE ALL
allc: clean all

#OBJECTS
main.o: main.cpp
	g++ -c main.cpp

Generic.o: Model/Generic.cpp
	g++ -c Model/Generic.cpp

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

#DAO
GenericDAO.o: DAO/GenericDAO.cpp
	g++ -c DAO/GenericDAO.cpp

CameraDAO.o: DAO/CameraDAO.cpp
	g++ -c DAO/CameraDAO.cpp

LenteDAO.o: DAO/LenteDAO.cpp
	g++ -c DAO/LenteDAO.cpp

#******************************
#TESTING
test: Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o
	clear
	g++ -o test -I/usr/local/include -I/usr/local/include/cppconn test.cpp Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o CameraDAO.o -lmysqlcppconn
	./test

#TESTING DB CONNECT
framework: Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o CameraDAO.o Generic.o
	g++ -o framework -I/usr/local/include -I/usr/local/include/cppconn framework.cpp Generic.o Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o CameraDAO.o -lmysqlcppconn
	./framework

#******************************
# CLEANING CONSOLE AND DIRECTORY
clean:
	clear
	rm -rf *o main test

.PHONY: test framework
