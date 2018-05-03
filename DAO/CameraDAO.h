#ifndef CameraDAO_H
#define CameraDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Camera.h"
#include "../Model/ProdutoPreco.h"

class CameraDAO : public GenericDAO{
  static std::string Table;
public:
  CameraDAO(sql::Connection *con);
  void insert(Camera camera);
  void update(int id, Camera camera);
  void remove(int id);
  Camera getById(int id);
  Camera getByIdWithPrice(int id);
  // findByMarca(); findByModelo();
  Camera find(string busca);
  Camera sqlToModel(sql::ResultSet *res);

};

#endif
