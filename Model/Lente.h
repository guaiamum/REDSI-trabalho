#ifndef Lente_H
#define Lente_H

#include "Produto.h"

class Lente : public Produto{
  bool Zoom;
  int Zoom_min;
  int Zoom_max;
  string Abertura;
public:
  Lente();
  Lente(int id, string marca, string modelo, int peso, bool zoom, int min, int max, string abertura);
  Lente(Lente const &lente);
  //GETTERS
  bool getZoom();
  int getZoom_min();
  int getZoom_max();
  string getAbertura();
  string getAllInfo();
  //SETTERS
  void setZoom(bool zoom);
  void setZoom_min(int zoom_min);
  void setZoom_max(int zoom_max);
  void setAbertura(string abertura);
  //OTHER
  bool validateAbertura(string abertura);
};

#endif
