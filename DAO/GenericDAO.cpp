#include "GenericDAO.h"

GenericDAO::GenericDAO(sql::Connection* con){
  this->con = con;
}
