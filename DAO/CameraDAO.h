#ifndef CameraDAO_H
#define CameraDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Camera.h"
#include "../Model/ProdutoPreco.h"

class CameraDAO : public GenericDAO{
  static std::string Table;
  Camera camera;
  ProdutoPreco preco;
public:
  CameraDAO(sql::Connection *con);
  void insert(Camera camera);
  void update(int id, Camera camera);
  // void removeById(int id);
  Camera getById(int id);
  Camera getByIdWithPrice(int id);
  // //findById(); findByMarca(); findByModelo();
  // void find(string busca);

};

#endif
