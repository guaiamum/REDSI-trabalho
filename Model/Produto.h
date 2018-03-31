#ifndef Produto_H
#define Produto_H

#include <string>

using namespace std;

class Produto{
protected:
  string Marca;
  string Modelo;
public:
  //GETTERS
  string getMarca();
  string getModelo();
  //SETTERS
  void setMarca(string marca);
  void setModelo(string modelo);
};

#endif
