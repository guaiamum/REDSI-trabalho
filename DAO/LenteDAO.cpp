#include "LenteDAO.h"

//TABLE NAME
string LenteDAO::Table("LENTE");

LenteDAO::LenteDAO(sql::Connection* con) : GenericDAO(con){
  // this->con = con;
}

Lente LenteDAO::getById(int id){
  sql::Statement *stmt;
  sql::ResultSet  *res;

  string query = "SELECT $.* FROM $ WHERE $.Id = " + std::to_string(id);
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);
  Lente lente = Lente();
  bool found = true;

  if (res->next()) {
    // bool Zoom;    int Zoom_min;    int Zoom_max;    string Abertura;
    lente.setId(res->getInt("Id"));
    lente.setMarca(res->getString("Marca"));
    lente.setModelo(res->getString("Modelo"));
    lente.setPeso(res->getInt("Peso"));
    // lente.setZoom(res->getInt("Zoom"));
    // lente.setZoom_min(res->getInt("Zoom_min"));
  } else {
    found = false;
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return lente;
}
