#include "Produto.h"

Produto::Produto(){
  Id = 0;
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
}

Produto::Produto(int id, string marca, string modelo, int peso){
  Id = id;
  Marca = marca;
  Modelo = modelo;
  Peso = peso;
}

//GETTERS
int Produto::getId(){
  return Id;
}
string Produto::getMarca(){
  return Marca;
}
string Produto::getModelo(){
  return Modelo;
}
int Produto::getPeso(){
  return Peso;
}
//SETTERS
void Produto::setId(int id){
  Id = id;
}
void Produto::setMarca(string marca){
  Marca = marca;
}
void Produto::setModelo(string modelo){
  Modelo = modelo;
}
void Produto::setPeso(int peso){
  Peso = peso;
}
