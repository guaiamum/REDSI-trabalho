#include "CameraDAO.h"
#include <iostream>

//TABLE NAME
string CameraDAO::Table("CAMERA");

CameraDAO::CameraDAO(sql::Connection* con){
  this->con = con;
}

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

Camera CameraDAO::getByIdWithPrice(int id){
  sql::Statement *stmt;
  sql::ResultSet  *res;

  string query = "SELECT $.*, PRODUTO_PRECO.Preco, PRODUTO_PRECO.Quantidade FROM $ INNER JOIN PRODUTO_PRECO ON $.Id = PRODUTO_PRECO.Id AND PRODUTO_PRECO.Tipo = '$' WHERE $.Id = " + std::to_string(id);
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);
  Camera camera = Camera();

  if (res->next()) {
    // Camera(string marca, string modelo, int peso, string sensor);
    camera.setId(res->getInt("Id"));
    camera.setMarca(res->getString("Marca"));
    camera.setModelo(res->getString("Modelo"));
    camera.setPeso(res->getInt("Peso"));
    camera.setSensor(res->getString("Sensor"));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return camera;
}
