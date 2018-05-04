#include <stdlib.h>
#include <iostream>
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
#include "Model/Camera.h"
#include "DAO/CameraDAO.h"
#include "Model/Lente.h"
#include "DAO/LenteDAO.h"

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



    //TESTING!!!!!
    int id; string busca;
    //CAMERA
    CameraDAO camera_manager = CameraDAO(con);
    // // Camera c1 = Camera("Nikon","D7000", 130,"Full-frame");
    // // camera_manager.insert(c1);
    // cout << "Digite o Id da camera: ";
    // cin >> id;
    // // Camera c2 = Camera("Canon,"7D",1450,"Full-frame");
    // // c2.setId(id);
    // // camera_manager.update(id, c2);
    // Camera c3 = camera_manager.getById(id);
    // cout << c3.getAllInfo() << endl;
    // camera_manager.remove(id);
    cout << "Digite a string a procurar: ";
    std::getline(std::cin,busca);
    list<Camera> lisCam = camera_manager.find(busca);
    cout << lisCam.front().getAllInfo() << endl;
    cout << lisCam.back().getAllInfo() << endl;

    //LENTE
    // LenteDAO lente_man = LenteDAO(con);
    // Lente l1 = Lente("Nikon", "Nikkor AF", 280, true, 70, 300, "1.8");
    // lente_man.insert(l1);
    // Lente l2 = Lente("Canon", "Fish-Eye", 320, false, 20, 0, "2.0");
    // cout << "Digite o Id da lente: ";
    // cin >> id;
    // lente_man.update(id,l2);
    // Lente l3 = lente_man.getById(1);
    // lente_man.update(id,l3);
    // cout << l3.getAllInfo() << endl;


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
