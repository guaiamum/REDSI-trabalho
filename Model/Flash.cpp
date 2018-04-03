#include "Flash.h"

Flash::Flash(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
}
Flash::Flash(string marca, string modelo, int peso){
  Marca = marca;
  Modelo = modelo;
  Peso = peso;
}

Flash::Flash(Flash const &flash){
  Marca = flash.Marca;
  Modelo = flash.Modelo;
  Peso = flash.Peso;
}
