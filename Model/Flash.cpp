#include "Flash.h"

Flash::Flash(){
  Id = 0;
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
}
Flash::Flash(int id, string marca, string modelo, int peso) : Produto(id, marca, modelo, peso) {}

Flash::Flash(Flash const &flash){
  Id = flash.Id;
  Marca = flash.Marca;
  Modelo = flash.Modelo;
  Peso = flash.Peso;
}

//GETTERS
string Flash::getAllInfo(){
  return Marca + ' ' + Modelo + " - " + std::to_string(Peso);
}
