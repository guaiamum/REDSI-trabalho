#ifndef Camera_H
#define Camera_H

#include "Produto.h"
#include <string>

using namespace std;

class Camera : public Produto{
  string Sensor;
public:
  Camera();
  Camera(int id, string marca, string modelo, int peso, string sensor);
  Camera(Camera const &camera);
  //GETTERS
  string getSensor();
  string getAllInfo();
  //SETTERS
  void setSensor(string sensor);
};

#endif
