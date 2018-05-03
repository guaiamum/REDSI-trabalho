#ifndef LenteDAO_H
#define LenteDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Lente.h"
#include "../Model/ProdutoPreco.h"

class LenteDAO : public GenericDAO{
  static std::string Table;
public:
  LenteDAO(sql::Connection *con);
  void insert(Lente lente);
  void update(int id, Lente lente);
  // void removeById(int id);
  Lente getById(int id);
  // Lente getByIdWithPrice(int id);
  Lente sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, Lente lente);

};

#endif
