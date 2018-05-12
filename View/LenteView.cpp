#ifndef LenteView_CPP
#define LenteView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/Lente.h"

using namespace std;

class LenteView {
public:
  inline static void printList(list<Lente> lentes, bool imprime_cabecalho = true, bool imprime_id = true);
  inline static void printOne(Lente lente, bool imprime_cabecalho = false, bool imprime_id = true);
};

void LenteView::printList(list<Lente> lentes, bool imprime_cabecalho, bool imprime_id){
  int espaco_inicial = (imprime_id) ? 5 : 0, espaco_meio = 15;

  //CABEÇALHO
  if(imprime_cabecalho){
    cout << setw(espaco_inicial) << ((imprime_id) ? "Id" : "")
    << setw(espaco_meio) << "Marca"
    << setw(espaco_meio) << "Modelo"
    << setw(espaco_meio) << "Zoom"
    << setw(espaco_meio) << "Abertura"
    << setw(espaco_meio) << "Peso"

    << endl << endl;
  }

  //CORPO
  for (auto c : lentes){
    cout << setw(espaco_inicial) << ((imprime_id) ? std::to_string(c.getId()) : "")
      << setw(espaco_meio) << c.getMarca()
      << setw(espaco_meio) << c.getModelo()
      << setw(espaco_meio) << c.getZoomString()
      << setw(espaco_meio) << c.getAbertura()
      << setw(espaco_meio) << c.getPeso() << "g"

      << endl;
  }
  cout << endl;
}

void LenteView::printOne(Lente lente, bool imprime_cabecalho, bool imprime_id){
  if(lente.getId() == 0){
    cout << "Lente não encontrada!\n";
    return;
  }

  list<Lente> uma_so;
  uma_so.push_back(lente);
  printList(uma_so, imprime_cabecalho, imprime_id);

}

#endif
