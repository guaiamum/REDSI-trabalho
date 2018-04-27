#include "CameraDAO.h"
// #include <iostream> //DEBUGING

//TABLE NAME
string CameraDAO::Table("CAMERA");

CameraDAO::CameraDAO(sql::Connection* con) : GenericDAO(con){}

/**
    Gets the firt object with the given Id.

    @param int Id.
    @return an object of the corresponding type.
*/
Camera CameraDAO::getById(int id){
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT $.* FROM $ WHERE $.Id = " + std::to_string(id);
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  Camera camera = sqlToModel(res);

  /* Free pointers */
  delete stmt;
  delete res;

  return camera;
}

/**
    Gets the firt object with the given Id joining with any results from the Price table

    @param int Id.
    @return an object of the corresponding type.
*/
Camera CameraDAO::getByIdWithPrice(int id){
  sql::Statement *stmt;
  sql::ResultSet  *res;

  string query = "SELECT $.*, PRODUTO_PRECO.Preco, PRODUTO_PRECO.Quantidade FROM $ INNER JOIN PRODUTO_PRECO ON $.Id = PRODUTO_PRECO.Id AND PRODUTO_PRECO.Tipo = '$' WHERE $.Id = " + std::to_string(id);
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);

  Camera camera = sqlToModel(res);

  /* Free pointers */
  delete stmt;
  delete res;

  return camera;
}

/**
    Inserts the given object.

    @param Object with set properties.
    @return nothing.
*/
void CameraDAO::insert(Camera camera){
  sql::PreparedStatement *stmt;
  string query = "INSERT INTO $(`Marca`, `Modelo`, `Peso`, `Sensor`) VALUES (?,?,?,?)";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setString(1,camera.getMarca());
  stmt->setString(2,camera.getModelo());
  stmt->setInt(3,camera.getPeso());
  stmt->setString(4,camera.getSensor());
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
void CameraDAO::update(int id, Camera camera){
  sql::PreparedStatement *stmt;
  string query = "UPDATE $ SET `Marca` = ?, `Modelo` = ?, `Peso` = ?, `Sensor` = ? WHERE Id = ?";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->prepareStatement(query);
  stmt->setString(1,camera.getMarca());
  stmt->setString(2,camera.getModelo());
  stmt->setInt(3,camera.getPeso());
  stmt->setString(4,camera.getSensor());
  stmt->setInt(5,id);
  /* Execute statement */
  stmt->execute();

  /* Free pointers */
  delete stmt;
}

/**
    Parses the ResultSet to the corresponding Model structure.

    @param ResultSet res.
    @return an object of the corresponding type.
*/
Camera CameraDAO::sqlToModel(sql::ResultSet *res){
  Camera camera = Camera();

  if (res->next()) {
    camera.setId(res->getInt("Id"));
    camera.setMarca(res->getString("Marca"));
    camera.setModelo(res->getString("Modelo"));
    camera.setPeso(res->getInt("Peso"));
    camera.setSensor(res->getString("Sensor"));
  }

  return camera;
}
