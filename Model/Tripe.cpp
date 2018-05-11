#include "Tripe.h"

Tripe::Tripe(){
  Id = 0;
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
  Carga_max = 1000; // 1Kg
}
Tripe::Tripe(string marca, string modelo, int peso, int carga_max) : Produto(id, marca, modelo, peso){
  Carga_max = carga_max;
}
Tripe::Tripe(Tripe const &tripe){
  Id = tripe.Id;
  Marca = tripe.Marca;
  Modelo = tripe.Modelo;
  Peso = tripe.Peso;
  Carga_max = tripe.Carga_max;
}

//GETTERS
int Tripe::getCarga_max(){
  return Carga_max;
}
string Tripe::getAllInfo(){
  return Marca + ' ' + Modelo + " - " + std::to_string(Peso) + " - carga: " + std::to_string(Carga_max);
}

//SETTERS
void Tripe::setCarga_max(int carga_max){
  Carga_max = carga_max;
}
