#ifndef CameraDAO_H
#define CameraDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Camera.h"
#include "ProdutoPrecoDAO.h"

class CameraDAO : public GenericDAO{
  static std::string Table;
public:
  CameraDAO(sql::Connection *con);
  // MODIFYING
  void insert(Camera camera);
  void update(Camera camera);
  void remove(int id);
  // READING
  Camera getById(int id);
  list<Camera> find(string busca);
  list<Camera> listAll();
  list<ProdutoPreco> getPriceById(int id);
  // PARSING
  Camera sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, Camera camera);

};

#endif
