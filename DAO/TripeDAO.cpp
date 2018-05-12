#include "TripeDAO.h"
// #include <iostream> //DEBUGING

/**
    Sets the current table name.
*/
string TripeDAO::Table("TRIPE");

/**
    Calls base class constructor to set the database connection to this class.

    @param sql Connection.
*/
TripeDAO::TripeDAO(sql::Connection* con) : GenericDAO(con){}

/**
    Gets the firt object with the given Id.

    @param int Id.
    @return an object .
*/
Tripe TripeDAO::getById(int id){
  sql::PreparedStatement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setInt(1,id);

  /* Executing query */  
  res = stmt->executeQuery();

  /* Parsing to Model structure */
  Tripe tripe;
  if(res->next()){
    tripe = sqlToModel(res);
  } 

  /* Free pointers */
  delete stmt;
  delete res;

  return tripe;
}


/**
    Gets all objects from the Price table

    @param int Id.
    @return an object.
*/
list<ProdutoPreco> TripeDAO::getPriceById(int id){
  ProdutoPrecoDAO *prod_man = new ProdutoPrecoDAO(this->con);
  list<ProdutoPreco> precos;

  /* Fetch results */
  precos = prod_man->getPriceByFk(id,this->Table);

  /* Free pointers */
  delete prod_man;

  return precos ;
}

/**
    Gets a list of objects corresponding to the search.

    @param int Id.
    @return an object .
*/
list<Tripe> TripeDAO::getByCarga_max(int carga){
  sql::PreparedStatement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE `Carga_max` >= ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setInt(1,carga);

  /* Execute statement */
  res = stmt->executeQuery();

  /* Parsing to Model structure */
  list<Tripe> tripes;
  while(res->next()){
    tripes.push_back(sqlToModel(res));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return tripes;
}

/**
    Inserts the given object.

    @param Object with set properties.
    @return nothing.
*/
void TripeDAO::insert(Tripe tripe){
  sql::PreparedStatement *stmt;
  string query = "INSERT INTO $(`Marca`, `Modelo`, `Peso`, `Carga_max`) VALUES (?,?,?,?)";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt,tripe);

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
void TripeDAO::update(Tripe tripe){
  sql::PreparedStatement *stmt;
  string query = "UPDATE $ SET `Marca` = ?, `Modelo` = ?, `Peso` = ?, `Carga_max` = ? WHERE Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt,tripe);
  stmt->setInt(5,tripe.getId());

  /* Execute statement */
  stmt->execute();

  /* Free pointers */
  delete stmt;
}

/**
    Parses the ResultSet to the corresponding Model structure.

    @param ResultSet res.
    @return an object .
*/
Tripe TripeDAO::sqlToModel(sql::ResultSet *res){
  return Tripe(
    res->getInt("Id"),
    res->getString("Marca"),
    res->getString("Modelo"),
    res->getInt("Peso"),
    res->getInt("Carga_max")
  );
}

/**
    Parses the Model structure to the PreparedStatement.

    @param ResultSet res.
    @return an object .
*/
void TripeDAO::modelToSql(sql::PreparedStatement *stmt, Tripe tripe){
  stmt->setString(1,tripe.getMarca());
  stmt->setString(2,tripe.getModelo());
  stmt->setInt(3,tripe.getPeso());
  stmt->setInt(4,tripe.getCarga_max());
}
