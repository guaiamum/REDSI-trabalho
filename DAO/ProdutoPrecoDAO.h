#ifndef ProdutoPrecoDAO_H
#define ProdutoPrecoDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/ProdutoPreco.h"

class ProdutoPrecoDAO : public GenericDAO{
  static std::string Table;
public:
  ProdutoPrecoDAO(sql::Connection *con);
  //MODIFYING
  void insert(ProdutoPreco produtoPreco);
  void update(ProdutoPreco produtoPreco);
  void remove(int id);
  //READING
  // ProdutoPreco getById(int id);
  // list<ProdutoPreco> find(string busca);
  // list<ProdutoPreco> listAll();
  list<ProdutoPreco> getPriceByFk(int id, string Tipo);
  // PARSING
  ProdutoPreco sqlToModel(sql::ResultSet *res);
  void modelToSql(sql::PreparedStatement *stmt, ProdutoPreco produtoPreco);

};

#endif
