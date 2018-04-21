#ifndef CameraDAO_H
#define CameraDAO_H

/* MYSQL */
#include "mysql_connection.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
/* OTHER */
#include <string>
#include "../Model/Generic.cpp"
#include "../Model/Camera.h"

class CameraDAO : public Camera {
  static string Table;
  sql::Connection* con;
public:
  CameraDAO(sql::Connection *con);
  void insert(Camera camera);
  void update(int id, Camera camera);
  // void removeById(int id);
  // void getById(int id);
  Camera getByIdWithPrice(int id);
  // //findById(); findByMarca(); findByModelo();
  // void find(string busca);

};

#endif
