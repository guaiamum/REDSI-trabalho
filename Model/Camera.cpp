#include "Camera.h"

Camera::Camera(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Peso = 0;
  Sensor = "Desconhecido";
}

Camera::Camera(string marca, string modelo, int peso, string sensor){
  Marca = marca;
  Modelo = modelo;
  Peso = peso;
  Sensor = sensor;
}

Camera::Camera(Camera const &camera){
  Marca = camera.Marca;
  Modelo = camera.Modelo;
  Peso = camera.Peso;
  Sensor = camera.Sensor;
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
