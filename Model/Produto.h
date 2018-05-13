#ifndef Produto_H
#define Produto_H

#include <string>
#include <list>
#include "ProdutoPreco.h"

using namespace std;

class Produto{
protected:
  int Id;
  string Marca;
  string Modelo;
  int Peso; //EM GRAMAS
public:
  Produto();
  Produto(int id, string marca, string modelo, int peso);
  // GETTERS
  int getId();
  string getMarca();
  string getModelo();
  int getPeso();
  // SETTERS
  void setId(int id);
  void setMarca(string marca);
  void setModelo(string modelo);
  void setPeso(int peso);
};

#endif
