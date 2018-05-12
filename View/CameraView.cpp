#ifndef CameraView_CPP
#define CameraView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/Camera.h"

using namespace std;

class CameraView {
public:
  inline static void printList(list<Camera> cameras, bool imprime_cabecalho = true, bool imprime_id = true);
  inline static void printOne(Camera camera, bool imprime_cabecalho = false, bool imprime_id = true);
};

void CameraView::printList(list<Camera> cameras, bool imprime_cabecalho, bool imprime_id){
  int espaco_inicial = (imprime_id) ? 5 : 0, espaco_meio = 15;

  //CABEÇALHO
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

#endif
