#ifndef LenteDAO_H
#define LenteDAO_H

/* OTHER */
#include "GenericDAO.h"
#include "../Model/Lente.h"
#include "../Model/ProdutoPreco.h"

class LenteDAO : public GenericDAO{
  static std::string Table;
  Lente lente;
  ProdutoPreco preco;
public:
  LenteDAO(sql::Connection *con);
  // void insert(Camera camera);
  // void update(int id, Camera camera);
  // void removeById(int id);
  Lente getById(int id);
  // Lente getByIdWithPrice(int id);
  // //findById(); findByMarca(); findByModelo();
  // void find(string busca);

};

#endif
