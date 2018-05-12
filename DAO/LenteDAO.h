#ifndef LenteDAO_H
#define LenteDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Lente.h"
#include "ProdutoPrecoDAO.h"

class LenteDAO : public GenericDAO{
  static std::string Table;
public:
  LenteDAO(sql::Connection *con);
  // MODIFYING
  void insert(Lente lente);
  void update(Lente lente);
  // void removeById(int id);
  // READING
  Lente getById(int id);
  list<Lente> getByMarca(string marca);
  list<ProdutoPreco> getPriceById(int id);
  //PARSING
  Lente sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, Lente lente);
};

#endif
