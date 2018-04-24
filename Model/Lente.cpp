#include "Lente.h"

Lente::Lente(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
  Zoom = true;
  Zoom_min = 18;
  Zoom_max = 55;
  Abertura = "5.6";
}

Lente::Lente(string marca, string modelo, int peso, bool zoom, int min, int max, string abertura){
  Marca = marca;
  Modelo = modelo;
  Peso = peso;
  Zoom = zoom;
  Zoom_min = min;
  Zoom_max = max;
  if(validateAbertura(abertura)){
    Abertura = abertura;
  } else {
    Abertura = "5.6";
  }
}

Lente::Lente(Lente const &lente){
  Marca = lente.Marca;
  Modelo = lente.Modelo;
  Peso = lente.Peso;
  Zoom = lente.Zoom;
  Zoom_min = lente.Zoom_min;
  Zoom_max = lente.Zoom_max;
  if(validateAbertura(lente.Abertura)){
    Abertura = lente.Abertura;
  } else {
    Abertura = "5.6";
  }
}

//GETTERS
bool Lente::getZoom(){
  return Zoom;
}
int Lente::getZoom_min(){
  return Zoom_min;
}
int Lente::getZoom_max(){
  return Zoom_max;
}
string Lente::getAbertura(){
  return Abertura;
}
string Lente::getAllInfo(){
  string zoom_max = (Zoom) ? "-" + std::to_string(Zoom_max) : "";
  return Marca + ' ' + Modelo + " - " + std::to_string(Zoom_min)+ zoom_max +"mm - " + (Abertura) + " (" + std::to_string(Peso) + "g)";
}

//SETTERS
void Lente::setZoom(bool zoom){
  Zoom = zoom;
}
void Lente::setZoom_min(int zoom_min){
  Zoom_min = zoom_min;
}
void Lente::setZoom_max(int zoom_max){
  Zoom_max = zoom_max;
}
void Lente::setAbertura(string abertura){
  if(validateAbertura(abertura)){
    Abertura = abertura;
  }
}

//OTHER
bool Lente::validateAbertura(string abertura){
  if(abertura == "1" || abertura == "1.1" || abertura == "1.2" || abertura == "1.4" ||
  abertura == "1.6" || abertura == "1.8" || abertura == "2" || abertura == "2.2" ||
  abertura == "2.5" || abertura == "2.8" || abertura == "3.2" || abertura == "3.5" ||
  abertura == "4" || abertura == "4.5" || abertura == "5" || abertura == "5.6" ||
  abertura == "6.3" || abertura == "7.1" || abertura == "8" || abertura == "9" ||
  abertura == "10" || abertura == "11" || abertura == "13" || abertura == "14" ||
  abertura == "16" || abertura == "18" || abertura == "20" || abertura == "22"){
    return true;
  }
  return false;
  // 1.0, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.5, 2.8, 3.2, 3.5, 4, 4.5, 5.0, 5.6, 6.3, 7.1, 8, 9, 10, 11, 13, 14, 16, 18, 20, 22
}
