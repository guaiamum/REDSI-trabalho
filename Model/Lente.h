#ifndef Lente_H
#define Lente_H

#include "Produto.h"

class Lente : public Produto{
  bool Zoom;
  int Zoom_min;
  int Zoom_max;
  float Abertura;  //1.0, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.5, 2.8, 3.2, 3.5, 4, 4.5, 5.0, 5.6, 6.3, 7.1, 8, 9, 10, 11, 13, 14, 16, 18, 20, 22
public:
  Lente();
  Lente(string marca, string modelo, int peso, bool zoom, int min, int max, float abertura);
  Lente(Lente const &lente);
  //GETTERS
  bool getZoom();
  int getZoom_min();
  int getZoom_max();
  float getAbertura();
  string getAllInfo();
  //SETTERS
  void setZoom(bool zoom);
  void setZoom_min(int zoom_min);
  void setZoom_max(int zoom_max);
  void setAbertura(float abertura);
};

#endif
