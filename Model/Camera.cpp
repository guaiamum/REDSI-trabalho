#include "Camera.h"

Camera::Camera() : Produto(){
  Sensor = "Desconhecido";
}

Camera::Camera(int id, string marca, string modelo, int peso, string sensor) : Produto(id, marca, modelo, peso){
  Sensor = sensor;
}

Camera::Camera(Camera const &camera){
  Id = camera.Id;
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
  return std::to_string(Id) + ": " + Marca + ' ' + Modelo + " - " + Sensor + " (" + std::to_string(Peso) + "g)";
}

//SETTERS
void Camera::setSensor(string sensor){
  Sensor = sensor;
}
