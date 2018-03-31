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
