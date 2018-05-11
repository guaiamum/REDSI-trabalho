#ifndef Tripe_H
#define Tripe_H

#include "Produto.h"

class Tripe : public Produto {
  int Carga_max;
public:
  Tripe();
  Tripe(int id, string marca, string modelo, int peso, int carga_max);
  Tripe(Tripe const &tripe);
  //GETTERS
  int getCarga_max();
  string getAllInfo();
  //SETTERS
  void setCarga_max(int carga_max);
};

#endif
