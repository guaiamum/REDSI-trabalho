#ifndef GenericDAO_H
#define GenericDAO_H

/* MYSQL */
#include "mysql_connection.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
/* OTHER */
#include <string>
#include "../Model/Generic.cpp"

class GenericDAO {
protected:
    sql::Connection* con;
    GenericDAO(sql::Connection *con);
};

#endif
