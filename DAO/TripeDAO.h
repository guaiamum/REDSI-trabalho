#ifndef TripeDAO_H
#define TripeDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Tripe.h"
#include "ProdutoPrecoDAO.h"

class TripeDAO : public GenericDAO{
  static std::string Table;
public:
  TripeDAO(sql::Connection *con);
  // MODIFYING
  void insert(Tripe tripe);
  void update(Tripe tripe);
  // void removeById(int id);
  // READING
  Tripe getById(int id);
  list<Tripe> getByCarga_max(int carga);
  list<ProdutoPreco> getPriceById(int id);
  //PARSING
  Tripe sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, Tripe tripe);
};

#endif
