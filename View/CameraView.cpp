#ifndef CameraView_CPP
#define CameraView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/Camera.h"

using namespace std;

class CameraView {
public:
  inline static void printList(list<Camera> cameras);
  inline static void printOne(Camera camera);
};

void CameraView::printList(list<Camera> cameras){
  int espaco_inicial = 5, espaco_meio = 15;

  //CABEÇALHO
  if(cameras.size() > 1){
  cout << setw(espaco_inicial) << "Id"
    << setw(espaco_meio) << "Marca"
    << setw(espaco_meio) << "Modelo"
    << setw(espaco_meio) << "Sensor"
    << setw(espaco_meio) << "Peso(g)"

    << endl << endl;
  }

  //CORPO
  for (auto c : cameras){
    cout << setw(espaco_inicial) << c.getId()
      << setw(espaco_meio) << c.getMarca()
      << setw(espaco_meio) << c.getModelo()
      << setw(espaco_meio) << c.getSensor()
      << setw(espaco_meio) << c.getPeso()

      << endl;
  }
  cout << endl;
}

void CameraView::printOne(Camera camera){
  if(camera.getId() == 0){
    cout << "Camera não encontrada!\n";
    return;
  }

  list<Camera> uma_so;
  uma_so.push_back(camera);
  printList(uma_so);

}

#endif
