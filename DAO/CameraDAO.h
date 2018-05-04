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
  //MODIFYING
  void insert(Camera camera);
  void update(int id, Camera camera);
  void remove(int id);
  //READING
  Camera getById(int id);
  list<Camera> find(string busca);
  // PARSING
  Camera sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, Camera camera);

};

#endif
