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
#include "Model/Generic.cpp"

#include "DAO/CameraDAO.h"
#include "View/CameraView.cpp"

#include "DAO/LenteDAO.h"
// #include "DAO/LenteView.cpp"

#include "DAO/ProdutoPrecoDAO.h"
#include "View/ProdutoPrecoView.cpp"

#include "Model/CarrinhoCompras.h"

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
    cout << "Conectando a base...\n";
    con = driver->connect(url, user, pass);
    /* Connect to the MySQL test database */
    con->setSchema(database);
    /* Create them tables */
    // stmt = con->createStatement();stmt->execute("DROP TABLE IF EXISTS test");stmt->execute("CREATE TABLE test(id INT)");delete stmt;

    // DECLARANDO VARIAVEIS
    string user; int id = 0; 
    CarrinhoCompras car = CarrinhoCompras();
    CameraDAO camera_manager = CameraDAO(con);
    ProdutoPrecoDAO precos_manager = ProdutoPrecoDAO(con);

    //INTRODUCAO
    cout << "\nDigite seu nome: ";
    std::getline(std::cin,user);

    //LISTAR CAMERAS
    cout << "\nOlá, " + user + "! A seguir estão as cameras disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    CameraView::printList(camera_manager.listAll());

    //SELECIONA CAMERA
    cout << "\nAgora entre com o Id da camera desejada:\n";
    id = Generic::readPosInt();
    car.camera = camera_manager.getById(id);
    cout << "A camera seguinte foi adicionada ao carrinho! ";
    CameraView::printOne(car.camera);

    //LISTA UNIDADES DE CAMERAS
    cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    ProdutoPrecoView::printList(camera_manager.getPriceById(id));

    //SELECIONA UNIDADE DE CAMERA
    cout << "\nAgora entre com o Id da unidade desejada:\n";
    id = Generic::readPosInt();
    car.precos.push_back(precos_manager.getById(id));
    cout << "Unidade adicionada ao carrinho!";
    // ProdutoPrecoView::printOne(car.precos);

    //LISTA LENTES MARCA
    


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
