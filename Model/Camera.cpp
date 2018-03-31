#include "Camera.h"

using namespace std;

Camera::Camera(){
  Marca = "Desconhecida";
  Modelo = "Desconhecido";
  Sensor = "Desconhecido";
}

Camera::Camera(string marca, string modelo, string sensor){
  Marca = marca;
  Modelo = modelo;
  Sensor = sensor;
}

Camera::Camera(Camera const &camera){
  Marca = camera.Marca;
  Modelo = camera.Modelo;
  Sensor = camera.Sensor;
}

//GETTERS
string Camera::getMarca(){
  return Marca;
}
string Camera::getModelo(){
  return Modelo;
}
string Camera::getSensor(){
  return Sensor;
}

//SETTERS
void Camera::setMarca(string marca){
  Marca = marca;
}
void Camera::setModelo(string modelo){
  Modelo = modelo;
}
void Camera::setSensor(string sensor){
  Sensor = sensor;
}
