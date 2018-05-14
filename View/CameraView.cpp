#ifndef CameraView_CPP
#define CameraView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/Camera.h"
#include "../Model/ProdutoPreco.h"

using namespace std;

class CameraView {
public:
  //printing
  inline static void printList(list<Camera> cameras, bool imprime_cabecalho = true, bool imprime_id = true);
  inline static void printOne(Camera camera, bool imprime_cabecalho = false, bool imprime_id = true);
  inline static void printWithPrice(Camera camera, ProdutoPreco preco);
  //reading
  inline static Camera readOne();
};

void CameraView::printList(list<Camera> cameras, bool imprime_cabecalho, bool imprime_id){
  int espaco_inicial = (imprime_id) ? 5 : 0, espaco_meio = 15;

  //CABEÃ‡ALHO
  if(imprime_cabecalho){
    cout << setw(espaco_inicial) << ((imprime_id) ?  "Id" : "")
    << setw(espaco_meio) << "Marca"
    << setw(espaco_meio) << "Modelo"
    << setw(espaco_meio) << "Sensor"
    << setw(espaco_meio) << "Peso"

    << endl << endl;
  }

  //CORPO
  for (auto c : cameras){
    cout << setw(espaco_inicial) << ((imprime_id) ? std::to_string(c.getId()) : "")
      << setw(espaco_meio) << c.getMarca()
      << setw(espaco_meio) << c.getModelo()
      << setw(espaco_meio) << c.getSensor()
      << setw(espaco_meio) << c.getPeso() << "g"

      << endl;
  }
  cout << endl;
}

void CameraView::printOne(Camera camera, bool imprime_cabecalho, bool imprime_id){
  if(camera.getId() == 0){
    cout << "Camera não encontrada!\n";
    return;
  }

  list<Camera> uma_so;
  uma_so.push_back(camera);
  printList(uma_so, imprime_cabecalho, imprime_id);

}

void CameraView::printWithPrice(Camera camera, ProdutoPreco preco){
  int espaco_inicial = 5, espaco_meio = 15;
  
  cout << setw(espaco_inicial) << camera.getMarca()
      << setw(espaco_meio) << camera.getModelo()
      << setw(espaco_meio) << camera.getSensor()
      << setw(espaco_meio) << camera.getPeso() << "g"

      << setw(espaco_meio) << preco.getNovoString()
      << setw(espaco_meio) << preco.getPreco()
      << endl << endl;
}

Camera CameraView::readOne(){
  Camera camera = Camera();
  string str; int inteiro = 0;

  cout <<  "Entre com a Marca: ";
  std::getline(std::cin,str);
  camera.setMarca(str);

  cout <<  "Entre com a Model: ";
  std::getline(std::cin,str);
  camera.setModelo(str);

  cout <<  "Entre com a Peso: ";
  cin >> inteiro;
  cin.ignore();  
  camera.setPeso(inteiro);

  cout <<  "Entre com a Sensor: ";
  std::getline(std::cin,str);
  camera.setSensor(str);

  return camera;
}

#endif