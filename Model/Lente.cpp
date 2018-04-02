#include "Lente.h"

Lente::Lente(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
  Zoom = true;
  Zoom_min = 18;
  Zoom_max = 55;
  Abertura = 5.6;
}

Lente::Lente(string marca, string modelo, int peso, bool zoom, int min, int max, float abertura){
  Marca = marca;
  Modelo = modelo;
  Peso = peso;
  Zoom = zoom;
  Zoom_min = min;
  Zoom_max = max;
  Abertura = abertura;
}

Lente::Lente(Lente const &lente){
  Marca = lente.Marca;
  Modelo = lente.Modelo;
  Peso = lente.Peso;
  Zoom = lente.Zoom;
  Zoom_min = lente.Zoom_min;
  Zoom_max = lente.Zoom_max;
  Abertura = lente.Abertura;
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
float Lente::getAbertura(){
  return Abertura;
}
string Lente::getAllInfo(){
  return Marca + ' ' + Modelo + " - " + std::to_string(Peso)+ " - " + std::to_string(Zoom_min)+ " - " + std::to_string(Zoom_max) + " - " + std::to_string(Abertura);
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
void Lente::setAbertura(float abertura){
  Abertura = abertura;
}
