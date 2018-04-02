#ifndef Camera_H
#define Camera_H

#include "Produto.h"
#include <string>

using namespace std;

class Camera : public Produto{
  string Sensor;
public:
  Camera();
  Camera(string marca, string modelo, string sensor, int peso);
  Camera(Camera const &camera);
  //GETTERS
  string getSensor();
  string getAllInfo();
  //SETTERS
  void setSensor(string sensor);
};

#endif
