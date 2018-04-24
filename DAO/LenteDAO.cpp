#include "LenteDAO.h"

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
    @return an object of the corresponding type.
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
    Parses the ResultSet to the corresponding Model structure.

    @param ResultSet res.
    @return an object of the corresponding type.
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
