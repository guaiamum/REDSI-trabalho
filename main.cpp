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

void fotografo(string user,CameraDAO camera_manager, ProdutoPrecoDAO precos_manager,LenteDAO lente_manager,FlashDAO flash_manager, TripeDAO tripe_manager);
void admin(string user,CameraDAO camera_manager, ProdutoPrecoDAO precos_manager,LenteDAO lente_manager,FlashDAO flash_manager, TripeDAO tripe_manager);

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
    //DAO's
    CameraDAO camera_manager = CameraDAO(con);
    ProdutoPrecoDAO precos_manager = ProdutoPrecoDAO(con);
    LenteDAO lente_manager = LenteDAO(con);
    FlashDAO flash_manager = FlashDAO(con);
    TripeDAO tripe_manager = TripeDAO(con);

    //INTRODUCAO
    cout << "\nDigite seu nome: ";
    std::getline(std::cin,user);

    while(id != 1 && id != 2){
      cout << "Deseja aceder a plataforma como cliente(1) ou administrador(2)? Digite a opcao desejada: ";
      id = Generic::readPosInt();
    }
    
    // USER OU ADMIN
    if(id == 1)
      fotografo(user, camera_manager, precos_manager, lente_manager, flash_manager, tripe_manager);
    else if (id == 2)
      admin(user, camera_manager, precos_manager, lente_manager, flash_manager, tripe_manager);

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

void fotografo(string user, 
  CameraDAO camera_manager,
  ProdutoPrecoDAO precos_manager,
  LenteDAO lente_manager, 
  FlashDAO flash_manager, 
  TripeDAO tripe_manager){
  /** DECLARANDO VARIAVEIS **/
  int id = 0;
  CarrinhoCompras car = CarrinhoCompras();
  
  /***************************************************************************/
  /******************             CAMERA              ************************/


  //LISTAR CAMERAS
  cout << "\nOlá, " + user + "! A seguir estão as cameras disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  CameraView::printList(camera_manager.listAll());
  //SELECIONA CAMERA
  Camera *camera = new Camera();
  //*VALIDACAO
  while(camera->getId() == 0){
    cout << "\nAgora entre com o Id da camera desejada:\n";
    id = Generic::readPosInt();
    camera = new Camera(camera_manager.getById(id));
  }
  car.camera = *camera;
  delete camera;
  cout << "A camera seguinte foi adicionada ao carrinho! ";
  CameraView::printOne(car.camera,false,false);

  //LISTA UNIDADES DE CAMERAS
  cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  ProdutoPrecoView::printList(camera_manager.getPriceById(id));
  //SELECIONA UNIDADE DE CAMERA
  ProdutoPreco *preco = new ProdutoPreco();
  //*VALIDACAO
  while(!car.validatePreco(*preco,"CAMERA",car.camera.getId())){
    cout << "\nAgora entre com o Id da unidade desejada:\n";
    id = Generic::readPosInt();
    preco = new ProdutoPreco(precos_manager.getById(id));
  }
  car.precos.push_back(*preco);
  delete preco;
  cout << "Unidade adicionada ao carrinho!" << endl;

  /***************************************************************************/
  /******************              LENTE              ************************/
  
  
  //LISTA LENTES MARCA
  const string marca = car.camera.getMarca();
  cout << "\n A seguir estão as lentes disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  LenteView::printList(lente_manager.getByMarca(marca));
  //SELECIONA LENTE
  Lente *lente = new Lente();
  //*VALIDACAO
  while(lente->getId() == 0 || lente->getMarca() != marca){
    cout << "\nAgora entre com o Id da lente desejada: ";
    id = Generic::readPosInt();
    lente = new Lente(lente_manager.getById(id));
  }
  car.lente = *lente;
  delete lente;
  cout << "A lente seguinte foi adicionada ao carrinho! ";
  LenteView::printOne(car.lente);

  //LISTA UNIDADES DE LENTES
  cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  ProdutoPrecoView::printList(lente_manager.getPriceById(id));
  //SELECIONA UNIDADE DE LENTE
  preco = new ProdutoPreco();
  while(!car.validatePreco(*preco,"LENTE",car.lente.getId())){
    cout << "\nAgora entre com o Id da unidade desejada:\n";
    id = Generic::readPosInt();
    preco = new ProdutoPreco(precos_manager.getById(id));
  }
  car.precos.push_back(*preco);
  delete preco;
  cout << "Unidade adicionada ao carrinho!" << endl;

  /***************************************************************************/
  /******************              FLASH              ************************/


  //LISTA FLASH MARCA
  cout << "\n A seguir estão os flashes disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  FlashView::printList(flash_manager.getByMarca(marca));
  //SELECIONA FLASH
  Flash *flash = new Flash();
  //*VALIDACAO
  while(flash->getId() == 0 || flash->getMarca() != marca){
    cout << "\nAgora entre com o Id do flash desejado: ";
    id = Generic::readPosInt();
    flash = new Flash(flash_manager.getById(id));
  }
  car.flash = *flash;
  delete flash;
  cout << "O flash seguinte foi adicionado ao carrinho! ";
  FlashView::printOne(car.flash);

  //LISTA UNIDADES DE FLASH
  cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  ProdutoPrecoView::printList(flash_manager.getPriceById(id));
  //SELECIONA UNIDADE DE FLASH
  preco = new ProdutoPreco();
  while(!car.validatePreco(*preco,"FLASH",car.flash.getId())){
    cout << "\nAgora entre com o Id da unidade desejada:\n";
    id = Generic::readPosInt();
    preco = new ProdutoPreco(precos_manager.getById(id));
  }
  car.precos.push_back(*preco);
  delete preco;
  cout << "Unidade adicionada ao carrinho!" << endl;

  /***************************************************************************/
  /******************              TRIPE              ************************/


  //LISTA TRIPE MARCA
  const int carga = car.getCarga();
  cout << "\n A seguir estão os tripes disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  TripeView::printList(tripe_manager.getByCarga_max(carga));
  //SELECIONA TRIPE
  Tripe *tripe = new Tripe();
  while(tripe->getId() == 0 || tripe->getCarga_max() < carga){
    cout << "\nAgora entre com o Id do tripe desejado: ";
    id = Generic::readPosInt();
    tripe = new Tripe(tripe_manager.getById(id));
  }
  car.tripe = *tripe;
  delete tripe;
  cout << "O tripe seguinte foi adicionado ao carrinho! ";
  TripeView::printOne(car.tripe);

  //LISTA UNIDADES DE TRIPE
  cout << "\n A seguir estão as unidades disponíveis, pressiona enter para prosseguir\n";
  cin.ignore();
  ProdutoPrecoView::printList(tripe_manager.getPriceById(id));
  //SELECIONA UNIDADE DE TRIPE
  preco = new ProdutoPreco();
  while(!car.validatePreco(*preco,"TRIPE",car.tripe.getId())){
    cout << "\nAgora entre com o Id da unidade desejada:\n";
    id = Generic::readPosInt();
    preco = new ProdutoPreco(precos_manager.getById(id));
  }
  car.precos.push_back(*preco);
  delete preco;
  cout << "Unidade adicionada ao carrinho!" << endl;
  
  /***************************************************************************/
  /******************            CARRINHO             ************************/


  CarrinhoComprasView::printProducts(car);
}

void admin(string user, 
  CameraDAO camera_manager,
  ProdutoPrecoDAO precos_manager,
  LenteDAO lente_manager, 
  FlashDAO flash_manager, 
  TripeDAO tripe_manager){
  
  int id = 0;
  cout << "\nOlá, " + user + "!\n";
  
  cout << "Digita 1 se deseja cadastrar uma camera: ";
  id = Generic::readPosInt();
  if(id == 1){
    Camera camera = CameraView::readOne();
    camera_manager.insert(camera);
    cout << "Camera cadatrada com sucesso! \n";
    // ProdutoPreco preco = ProdutoPrecoView::readOne(ca);
    // precos_manager.insert(preco);
  }

}