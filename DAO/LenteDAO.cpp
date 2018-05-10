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
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT $.* FROM $ WHERE $.Id = " + std::to_string(id);
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  Lente lente = sqlToModel(res);

  /* Free pointers */
  delete stmt;
  delete res;

  return lente;
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
  Lente lente = Lente();

  /* Checks if there are results, and set the properties */
  if (res->next()) {
      lente.setId(res->getInt("Id"));
      lente.setMarca(res->getString("Marca"));
      lente.setModelo(res->getString("Modelo"));
      lente.setPeso(res->getInt("Peso"));
      lente.setZoom(res->getInt("Zoom"));
      lente.setZoom_min(res->getInt("Zoom_min"));
      lente.setZoom_max(res->getInt("Zoom_max"));
      lente.setAbertura(res->getString("Abertura"));
    }

  return lente;
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
