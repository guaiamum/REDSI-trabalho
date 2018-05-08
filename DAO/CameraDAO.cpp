#include "CameraDAO.h"
// #include <iostream> //DEBUGING

//TABLE NAME
string CameraDAO::Table("CAMERA");

CameraDAO::CameraDAO(sql::Connection* con) : GenericDAO(con){}

/**
    Finds all objects with properties that look like the given string.

    @param string Busca.
    @return list of objects.
*/
list<Camera> CameraDAO::find(string busca){
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE (CONCAT(`Marca`,`Modelo`,`Sensor`) LIKE '%" + busca + "%')";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing and executing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  list<Camera> cameras;
  while(res->next()){
    cameras.push_back(sqlToModel(res));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return cameras;
}

/**
    Finds all objects with properties that look like the given string.

    @param string Busca.
    @return list of objects.
*/
list<Camera> CameraDAO::listAll(){
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ LIMIT 30";
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing and executing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  list<Camera> cameras;
  while(res->next()){
    cameras.push_back(sqlToModel(res));
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return cameras;
}

/**
    Gets the firt object with the given Id.

    @param int Id.
    @return an objec.
*/
Camera CameraDAO::getById(int id){
  sql::Statement *stmt;
  sql::ResultSet  *res;
  string query = "SELECT * FROM $ WHERE Id = " + std::to_string(id);
  Generic::findAndReplaceAll(query, "$", this->Table);

  /* Preparing and executing statement */
  stmt = this->con->createStatement();
  res = stmt->executeQuery(query);

  /* Parsing to Model structure */
  Camera camera;
  if(res->next()){
    camera = sqlToModel(res);
  }

  /* Free pointers */
  delete stmt;
  delete res;

  return camera;
}

/**
    Gets the firt object with the given Id joining with any results from the Price table

    @param int Id.
    @return an object.
*/
// list<ProdutoPreco> CameraDAO::getPriceById(int id){
//   sql::PreparedStatement *stmt;
//   sql::ResultSet  *res;
//   string query = "SELECT * FROM PRODUTO_PRECO WHERE `Tipo` = '$' AND PRODUTO_PRECO.Fk_Produto = ?";
//   Generic::findAndReplaceAll(query, "$", this->Table);
//
//   /* Preparing statement */
//   stmt = this->con->prepareStatement(query);
//   stmt->setInt(1,id);
//
//   /* Execute statement */
//   // res = stmt->executeQuery(query);
//
//   /* Parsing to Model structure */
//   list<ProdutoPreco> precos; precos.push_back(ProdutoPreco());
//   // if(res->next()){
//   //   precos.push_back(priceSqlToModel(res));
//   // }
//
//   /* Free pointers */
//   delete stmt;
//   delete res;
//
//   return precos;
// }

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
  modelToSql(stmt, camera);

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
  modelToSql(stmt, camera);
  stmt->setInt(5,id);
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
void CameraDAO::remove(int id){
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
Camera CameraDAO::sqlToModel(sql::ResultSet *res){
  return Camera(
    res->getInt("Id"),
    res->getString("Marca"),
    res->getString("Modelo"),
    res->getInt("Peso"),
    res->getString("Sensor"));
}

/**
    Parses the ResultSet to the corresponding Model structure.

    @param ResultSet res.
    @return an object.
*/
ProdutoPreco CameraDAO::priceSqlToModel(sql::ResultSet *res){
  return ProdutoPreco(
    res->getInt("Fk_Produto"),
    res->getString("Tipo_Produto"),
    res->getInt("Quantidade"),
    res->getDouble("Preco"),
    res->getBoolean("Novo"));
}

/**
    Parses the Model structure to the PreparedStatement.

    @param ResultSet res.
    @return an object .
*/
void CameraDAO::modelToSql(sql::PreparedStatement *stmt, Camera camera){
  stmt->setString(1,camera.getMarca());
  stmt->setString(2,camera.getModelo());
  stmt->setInt(3,camera.getPeso());
  stmt->setString(4,camera.getSensor());
}
