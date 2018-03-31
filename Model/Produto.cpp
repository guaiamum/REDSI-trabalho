#include "Produto.h"

//GETTERS
string Produto::getMarca(){
  return Marca;
}
string Produto::getModelo(){
  return Modelo;
}

//SETTERS
void Produto::setMarca(string marca){
  Marca = marca;
}
void Produto::setModelo(string modelo){
  Modelo = modelo;
}
