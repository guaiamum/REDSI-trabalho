#include "Camera.h"

Camera::Camera(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
  Sensor = "Desconhecido";
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
