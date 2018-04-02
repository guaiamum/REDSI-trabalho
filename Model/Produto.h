#ifndef Produto_H
#define Produto_H

#include <string>

using namespace std;

class Produto{
protected:
  string Marca;
  string Modelo;
  int Peso; //EM GRAMAS
public:
  //GETTERS
  string getMarca();
  string getModelo();
  int getPeso();
  //SETTERS
  void setMarca(string marca);
  void setModelo(string modelo);
  void setPeso(int peso);
};

#endif
