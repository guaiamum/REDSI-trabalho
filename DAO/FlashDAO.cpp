#include "FlashDAO.h"
// #include <iostream> //DEBUGING

/**
    Sets the current table name.
*/
string FlashDAO::Table("FLASH");

/**
    Calls base class constructor to set the database connection to this class.

    @param sql Connection.
*/
FlashDAO::FlashDAO(sql::Connection* con) : GenericDAO(con){}

/**
    Gets the firt object with the given Id.

    @param int Id.
    @return an object .
*/
Flash FlashDAO::getById(int id){
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
  Flash flash;
  if(res->next()){
    flash = sqlToModel(res);
  } 

  /* Free pointers */
  delete stmt;
  delete res;

  return flash;
}


/**
    Gets all objects from the Price table

    @param int Id.
    @return an object.
*/
list<ProdutoPreco> FlashDAO::getPriceById(int id){
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
list<Flash> FlashDAO::getByMarca(string marca){
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE `Marca` LIKE '%"+marca+"%'";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();

  /* Execute statement */
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  list<Flash> flashs;
  while(res->next()){
    flashs.push_back(sqlToModel(res));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return flashs;
}

/**
    Inserts the given object.

    @param Object with set properties.
    @return nothing.
*/
void FlashDAO::insert(Flash flash){
  sql::PreparedStatement *stmt;
  string query = "INSERT INTO $(`Marca`, `Modelo`, `Peso`) VALUES (?,?,?)";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt,flash);

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
void FlashDAO::update(Flash flash){
  sql::PreparedStatement *stmt;
  string query = "UPDATE $ SET `Marca` = ?, `Modelo` = ?, `Peso` = ? WHERE Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt,flash);
  stmt->setInt(4,flash.getId());

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
Flash FlashDAO::sqlToModel(sql::ResultSet *res){
  return Flash(
    res->getInt("Id"),
    res->getString("Marca"),
    res->getString("Modelo"),
    res->getInt("Peso")
  );
}

/**
    Parses the Model structure to the PreparedStatement.

    @param ResultSet res.
    @return an object .
*/
void FlashDAO::modelToSql(sql::PreparedStatement *stmt, Flash flash){
  stmt->setString(1,flash.getMarca());
  stmt->setString(2,flash.getModelo());
  stmt->setInt(3,flash.getPeso());
}
