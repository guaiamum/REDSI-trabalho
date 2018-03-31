#ifndef Camera_H
#define Camera_H

#include <string>

using namespace std;

class Camera{
  string Marca;
  string Modelo;
  string Sensor;
public:
  Camera();
  Camera(string marca, string modelo, string sensor);
  Camera(Camera const &camera);
  //GETTERS
  string getMarca();
  string getModelo();
  string getSensor();
  //SETTERS
  void setMarca(string marca);
  void setModelo(string modelo);
  void setSensor(string sensor);
};

#endif
