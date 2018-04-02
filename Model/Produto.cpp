#include "Produto.h"


//GETTERS
std::string Produto::getMarca(){
  return Marca;
}
std::string Produto::getModelo(){
  return Modelo;
}
int Produto::getPeso(){
  return Peso;
}
//SETTERS
void Produto::setMarca(std::string marca){
  Marca = marca;
}
void Produto::setModelo(std::string modelo){
  Modelo = modelo;
}
void Produto::setPeso(int peso){
  Peso = peso;
}
