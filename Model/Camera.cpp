#include "Camera.h"

using namespace std;

Camera::Camera(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Sensor = "Desconhecido";
  Peso = 0;
}

Camera::Camera(string marca, string modelo, string sensor, int peso){
  Marca = marca;
  Modelo = modelo;
  Sensor = sensor;
  Peso = peso;
}

Camera::Camera(Camera const &camera){
  Marca = camera.Marca;
  Modelo = camera.Modelo;
  Sensor = camera.Sensor;
  Peso = camera.Peso;
}

//GETTERS
string Camera::getSensor(){
  return Sensor;
}
string Camera::getAllInfo(){
  return Marca + ' ' + Modelo + " - " + Sensor;
}

//SETTERS
void Camera::setSensor(string sensor){
  Sensor = sensor;
}
