#include "LenteDAO.h"
// #include <iostream> //DEBUGING

/**
    Sets the current table name.
*/
string LenteDAO::Table("LENTE");

/**
    Calls base class constructor to set the database connection to this class.

    @param sql Connection.
*/
LenteDAO::LenteDAO(sql::Connection* con) : GenericDAO(con){}

/**
    Gets the firt object with the given Id.

    @param int Id.
    @return an object .
*/
Lente LenteDAO::getById(int id){
  sql::PreparedStatement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT $.* FROM $ WHERE $.Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setInt(1,id);

  /* Executing query */  
  res = stmt->executeQuery();

  /* Parsing to Model structure */
  Lente lente;
  if(res->next()){
    lente = sqlToModel(res);
  } 

  /* Free pointers */
  delete stmt;
  delete res;

  return lente;
}


/**
    Gets all objects from the Price table

    @param int Id.
    @return an object.
*/
list<ProdutoPreco> LenteDAO::getPriceById(int id){
  ProdutoPrecoDAO *prod_man = new ProdutoPrecoDAO(this->con);
  list<ProdutoPreco> precos;

  precos = prod_man->getPriceByFk(id,this->Table);

  delete prod_man;

  return precos ;
}

/**
    Gets a list of objects corresponding to the search.

    @param int Id.
    @return an object .
*/
list<Lente> LenteDAO::getByMarca(string marca){
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE `Marca` LIKE '%"+marca+"%'";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();

  /* Execute statement */
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  list<Lente> lentes;
  while(res->next()){
    lentes.push_back(sqlToModel(res));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return lentes;
}

/**
    Inserts the given object.

    @param Object with set properties.
    @return nothing.
*/
void LenteDAO::insert(Lente lente){
  sql::PreparedStatement *stmt;
  string query = "INSERT INTO $(`Marca`, `Modelo`, `Peso`, `Zoom`, `Zoom_min`, `Zoom_max`, `Abertura`) VALUES (?,?,?,?,?,?,?)";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt,lente);

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
void LenteDAO::update(Lente lente){
  sql::PreparedStatement *stmt;
  string query = "UPDATE $ SET `Marca` = ?, `Modelo` = ?, `Peso` = ?, `Zoom` = ?, `Zoom_min` = ?, `Zoom_max` = ?, `Abertura` = ? WHERE Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  modelToSql(stmt,lente);
  stmt->setInt(8,lente.getId());

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
Lente LenteDAO::sqlToModel(sql::ResultSet *res){
  return Lente(
    res->getInt("Id"),
    res->getString("Marca"),
    res->getString("Modelo"),
    res->getInt("Peso"),
    res->getInt("Zoom"),
    res->getInt("Zoom_min"),
    res->getInt("Zoom_max"),
    res->getString("Abertura")
  );
}

/**
    Parses the Model structure to the PreparedStatement.

    @param ResultSet res.
    @return an object .
*/
void LenteDAO::modelToSql(sql::PreparedStatement *stmt, Lente lente){
  stmt->setString(1,lente.getMarca());
  stmt->setString(2,lente.getModelo());
  stmt->setInt(3,lente.getPeso());
  stmt->setBoolean(4,lente.getZoom());
  stmt->setInt(5,lente.getZoom_min());
  if(lente.getZoom()){
    stmt->setInt(6,lente.getZoom_max());
  } else {
    stmt->setNull(6,0);
  }
  stmt->setString(7,lente.getAbertura());

}
