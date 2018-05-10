#include "ProdutoPrecoDAO.h"
// #include <iostream> //DEBUG

//TABLE NAME
string ProdutoPrecoDAO::Table("PRODUTO_PRECO");

ProdutoPrecoDAO::ProdutoPrecoDAO(sql::Connection* con) : GenericDAO(con){}

/**
    Gets all objects with the given Fk

    @param int Id.
    @return an object.
*/
list<ProdutoPreco> ProdutoPrecoDAO::getPriceByFk(int id, string Tipo){
  sql::PreparedStatement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE `Tipo_Produto` = '#tipo' AND PRODUTO_PRECO.Fk_Produto = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);
  Generic::findAndReplaceAll(query, "#tipo", Tipo);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setInt(1,id);

  /* Execute statement */
  res = stmt->executeQuery();

  /* Parsing to Model structure */
  list<ProdutoPreco> precos;
  while(res->next()){
    precos.push_back(sqlToModel(res));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return precos;
}


/**
    Inserts the given object.

    @param Object with set properties.
    @return nothing.
*/
void ProdutoPrecoDAO::insert(ProdutoPreco produtoPreco){
  sql::PreparedStatement *stmt;
  string query = "INSERT INTO $(`Fk_Produto`,`Tipo_Produto`,`Quantidade`,`Preco`, `Novo`) VALUES (?,?,?,?,?)";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt, produtoPreco);

  /* Execute statement */
  stmt->execute();

  /* Free pointers */
  delete stmt;
}

/**
    Updates the object of the given Id.

    @param int Id, Object with set properties.
    @return nothing.
*/
void ProdutoPrecoDAO::update(ProdutoPreco produtoPreco){
  sql::PreparedStatement *stmt;
  string query = "UPDATE $ SET `Fk_Produto`=?,`Tipo_Produto`=?,`Quantidade`=?,`Preco`=?, `Novo`=? WHERE Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt, produtoPreco);
  stmt->setInt(6,produtoPreco.getId());
  /* Execute statement */
  stmt->execute();

  /* Free pointers */
  delete stmt;
}

/**
    Removes the object of the given Id.

    @param int Id.
    @return nothing.
*/
void ProdutoPrecoDAO::remove(int id){
  sql::PreparedStatement *stmt;
  string query = "DELETE FROM $ WHERE Id = ? LIMIT 1";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setInt(1,id);

  /* Execute statement */
  stmt->execute();

  /* Free pointers */
  delete stmt;
}

/**
    Parses the ResultSet to the corresponding Model structure.

    @param ResultSet res.
    @return an object.
*/
ProdutoPreco ProdutoPrecoDAO::sqlToModel(sql::ResultSet *res){
  return ProdutoPreco(
    res->getInt("Id"),
    res->getInt("Fk_Produto"),
    res->getString("Tipo_Produto"),
    res->getInt("Quantidade"),
    res->getDouble("Preco"),
    res->getBoolean("Novo"));
}
//ProdutoPreco
/**
    Parses the Model structure to the PreparedStatement.

    @param ResultSet res.
    @return an object .
*/
void ProdutoPrecoDAO::modelToSql(sql::PreparedStatement *stmt, ProdutoPreco produtoPreco){
  stmt->setInt(1,produtoPreco.getFk_Produto());
  stmt->setString(2,produtoPreco.getTipo_Produto());
  stmt->setInt(3,produtoPreco.getQuantidade());
  stmt->setDouble(4,produtoPreco.getPreco());
  stmt->setBoolean(5,produtoPreco.getNovo());
}
