#COMPILE ALL
all: main.o Produto.o Camera.o Lente.o Flash.o Tripe.o ProdutoPreco.o Generic.o GenericDAO.o CameraDAO.o LenteDAO.o FlashDAO.o TripeDAO.o ProdutoPrecoDAO.o CameraView.o CarrinhoCompras.o LenteView.o CarrinhoComprasView.o FlashView.o TripeView.o
	g++ -o main -I/usr/local/include -I/usr/local/include/cppconn main.o Generic.o GenericDAO.o Produto.o Camera.o CameraDAO.o Lente.o LenteDAO.o FlashDAO.o TripeDAO.o Flash.o Tripe.o ProdutoPreco.o CameraView.o CarrinhoCompras.o ProdutoPrecoDAO.o LenteView.o CarrinhoComprasView.o FlashView.o TripeView.o -lmysqlcppconn

#CLEAN AND COMPILE ALL
allc: clean all

#OBJECTS
main.o: main.cpp
	g++ -c main.cpp -std=c++11

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

FlashDAO.o: DAO/FlashDAO.cpp
	g++ -c DAO/FlashDAO.cpp

TripeDAO.o: DAO/TripeDAO.cpp
	g++ -c DAO/TripeDAO.cpp

# VIEW
CameraView.o: View/CameraView.cpp
	g++ -c View/CameraView.cpp -std=c++11

ProdutoPrecoView.o: View/ProdutoPrecoView.cpp
	g++ -c View/ProdutoPrecoView.cpp -std=c++11

LenteView.o: View/LenteView.cpp
	g++ -c View/LenteView.cpp -std=c++11

CarrinhoComprasView.o: View/CarrinhoComprasView.cpp
	g++ -c View/CarrinhoComprasView.cpp -std=c++11

FlashView.o: View/FlashView.cpp
	g++ -c View/FlashView.cpp -std=c++11

TripeView.o: View/TripeView.cpp
	g++ -c View/TripeView.cpp -std=c++11

#******************************
# CLEANING CONSOLE AND DIRECTORY
clean:
	clear
	rm -rf *o main test

