#COMPILE ALL
all: main.o Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o Generic.o GenericDAO.o CameraDAO.o LenteDAO.o ProdutoPrecoDAO.o CameraView.o CarrinhoCompras.o LenteView.o CarrinhoComprasView.o
	g++ -o main -I/usr/local/include -I/usr/local/include/cppconn main.o Generic.o GenericDAO.o Produto.o Camera.o CameraDAO.o Lente.o LenteDAO.o Flash.o Tripe.o ProdutoPreco.o CameraView.o CarrinhoCompras.o ProdutoPrecoDAO.o LenteView.o CarrinhoComprasView.o -lmysqlcppconn

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

CarrinhoCompras.o: Model/CarrinhoCompras.cpp
	g++ -c Model/CarrinhoCompras.cpp

#DAO
GenericDAO.o: DAO/GenericDAO.cpp
	g++ -c DAO/GenericDAO.cpp

CameraDAO.o: DAO/CameraDAO.cpp
	g++ -c DAO/CameraDAO.cpp

LenteDAO.o: DAO/LenteDAO.cpp
	g++ -c DAO/LenteDAO.cpp

ProdutoPrecoDAO.o: DAO/ProdutoPrecoDAO.cpp
	g++ -c DAO/ProdutoPrecoDAO.cpp

# VIEW
CameraView.o: View/CameraView.cpp
	g++ -c View/CameraView.cpp

ProdutoPrecoView.o: View/ProdutoPrecoView.cpp
	g++ -c View/ProdutoPrecoView.cpp

LenteView.o: View/LenteView.cpp
	g++ -c View/LenteView.cpp

CarrinhoComprasView.o: View/CarrinhoComprasView.cpp
	g++ -c View/CarrinhoComprasView.cpp


#******************************
# CLEANING CONSOLE AND DIRECTORY
clean:
	clear
	rm -rf *o main test

