#ifndef FlashDAO_H
#define FlashDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Flash.h"
#include "ProdutoPrecoDAO.h"

class FlashDAO : public GenericDAO{
  static std::string Table;
public:
  FlashDAO(sql::Connection *con);
  // MODIFYING
  void insert(Flash flash);
  void update(Flash flash);
  // void removeById(int id);
  // READING
  Flash getById(int id);
  list<Flash> getByMarca(string marca);
  list<ProdutoPreco> getPriceById(int id);
  //PARSING
  Flash sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, Flash flash);
};

#endif
