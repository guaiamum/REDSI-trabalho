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
#include "View/LenteView.cpp"

#include "DAO/FlashDAO.h"
#include "View/FlashView.cpp"

#include "DAO/TripeDAO.h"
#include "View/TripeView.cpp"

#include "DAO/ProdutoPrecoDAO.h"
#include "View/ProdutoPrecoView.cpp"

#include "Model/CarrinhoCompras.h"
#include "View/CarrinhoComprasView.cpp"

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
    //DAO's
    CameraDAO camera_manager = CameraDAO(con);
    ProdutoPrecoDAO precos_manager = ProdutoPrecoDAO(con);
    LenteDAO lente_manager = LenteDAO(con);
    FlashDAO flash_manager = FlashDAO(con);
    TripeDAO tripe_manager = TripeDAO(con);

    //INTRODUCAO
    cout << "\nDigite seu nome: ";
    std::getline(std::cin,user);

    /***************************************************************************/
    /******************             CAMERA              ************************/


    //LISTAR CAMERAS
    cout << "\nOlá, " + user + "! A seguir estão as cameras disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    CameraView::printList(camera_manager.listAll());
    //SELECIONA CAMERA
    Camera *camera = new Camera();
    while(camera->getId() == 0){
      cout << "\nAgora entre com o Id da camera desejada:\n";
      id = Generic::readPosInt();
      camera = new Camera(camera_manager.getById(id));
    }
    car.camera = *camera;
    delete camera;
    cout << "A camera seguinte foi adicionada ao carrinho! ";
    CameraView::printOne(car.camera);

    //LISTA UNIDADES DE CAMERAS
    cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    ProdutoPrecoView::printList(camera_manager.getPriceById(id));
    //SELECIONA UNIDADE DE CAMERA
    ProdutoPreco *preco = new ProdutoPreco();
    while(!car.validatePreco(preco->getTipo_Produto(),"CAMERA")){
      cout << "\nAgora entre com o Id da unidade desejada:\n";
      id = Generic::readPosInt();
      preco = new ProdutoPreco(precos_manager.getById(id));
    }
    car.precos.push_back(*preco);
    cout << "Unidade adicionada ao carrinho!" << endl;

    /***************************************************************************/
    /******************              LENTE              ************************/
    
    
    //LISTA LENTES MARCA
    static string marca = car.camera.getMarca();
    cout << "\n A seguir estão as lentes disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    LenteView::printList(lente_manager.getByMarca(marca));
    //SELECIONA LENTE
    cout << "\nAgora entre com o Id da lente desejada: ";
    id = Generic::readPosInt();
    car.lente = lente_manager.getById(id);
    cout << "A lente seguinte foi adicionada ao carrinho! ";
    LenteView::printOne(car.lente);

    //LISTA UNIDADES DE LENTES
    cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    ProdutoPrecoView::printList(lente_manager.getPriceById(id));
    //SELECIONA UNIDADE DE LENTE
    cout << "\nAgora entre com o Id da unidade desejada: ";
    id = Generic::readPosInt();
    car.precos.push_back(precos_manager.getById(id));
    cout << "Unidade adicionada ao carrinho!" << endl;

    /***************************************************************************/
    /******************              FLASH              ************************/


    //LISTA FLASH MARCA
    cout << "\n A seguir estão os flashes disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    FlashView::printList(flash_manager.getByMarca(marca));
    //SELECIONA FLASH
    cout << "\nAgora entre com o Id do flash desejado: ";
    id = Generic::readPosInt();
    car.flash = flash_manager.getById(id);
    cout << "O flash seguinte foi adicionado ao carrinho! ";
    FlashView::printOne(car.flash);

    //LISTA UNIDADES DE FLASH
    cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
    cin.ignore();
    ProdutoPrecoView::printList(flash_manager.getPriceById(id));
    //SELECIONA UNIDADE DE FLASH
    cout << "\nAgora entre com o Id da unidade desejada: ";
    id = Generic::readPosInt();
    car.precos.push_back(precos_manager.getById(id));
    cout << "Unidade adicionada ao carrinho!" << endl;

    /***************************************************************************/
    /******************            CARRINHO             ************************/


    CarrinhoComprasView::printProducts(car);

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

  cout << "Bye :)" << endl;
  return EXIT_SUCCESS;
}
