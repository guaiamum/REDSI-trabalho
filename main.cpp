#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
/* uncomment for applications that use vectors */
/*#include <vector>*/

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "info.cpp"
// #include "Model/Generic.cpp"

// #include "Model/Camera.h"
#include "DAO/CameraDAO.h"
#include "View/CameraView.cpp"

#include "DAO/LenteDAO.h"

// #include "DAO/ProdutoPrecoDAO.h"
#include "View/ProdutoPrecoView.cpp"

using namespace std;


int main(int argc, const char **argv)
{
  string url(argc >= 2 ? argv[1] : HOST);
  const string user(argc >= 3 ? argv[2] : USER);
  const string pass(argc >= 4 ? argv[3] : PASS);
  const string database(argc >= 5 ? argv[4] : DB);

  try {
    sql::Driver *driver;
    sql::Connection *con;

    /* Create a connection */
    driver = get_driver_instance();
    con = driver->connect(url, user, pass);
    /* Connect to the MySQL test database */
    con->setSchema(database);
    /* Create them tables */
    // stmt = con->createStatement();
    // stmt->execute("DROP TABLE IF EXISTS test");
    // stmt->execute("CREATE TABLE test(id INT)");
    // delete stmt;


    //INTRODUCAO
    string user; int id = 0;
    cout << "Digite seu nome: ";
    std::getline(std::cin,user);

    //LISTAR CAMERAS
    cout << "\nOlá, " + user + "! A seguir estão as cameras disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    CameraDAO cam_man = CameraDAO(con);
    CameraView::printList(cam_man.listAll());

    //SELECIONA CAMERA
    cout << "\nAgora entre com o Id da camera desejada:\n";
    id = Generic::readPosInt();
    CameraView::printOne(cam_man.getById(id));

    //LISTA PRECOS
    cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    ProdutoPrecoView::printList(cam_man.getPriceById(id));

    //SELECIONA PRECO
    // cout << "\nAgora entre com o Id da unidade desejada:\n";
    // id = Generic::readPosInt();
    // CameraView::printOne(cam_man.getById(id));



    /* FREE POINTERS */
    delete con;

  } catch (sql::SQLException &e) {
    /*
      MySQL Connector/C++ throws three different exceptions:

      - sql::MethodNotImplementedException (derived from sql::SQLException)
      - sql::InvalidArgumentException (derived from sql::SQLException)
      - sql::SQLException (derived from std::runtime_error)
    */
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    /* what() (derived from std::runtime_error) fetches error message */
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;

    return EXIT_FAILURE;
  }

  cout << "Done." << endl;
  return EXIT_SUCCESS;
}
