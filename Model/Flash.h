#ifndef Flash_H
#define Flash_H

#include "Produto.h"

class Flash : public Produto {
public:
  Flash();
  Flash(int id, string marca, string modelo, int peso);
  Flash(Flash const &flash);
  //GETTERS
  string getAllInfo();
};

#endif
