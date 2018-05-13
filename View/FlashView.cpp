#ifndef FlashView_CPP
#define FlashView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/Flash.h"

using namespace std;

class FlashView {
public:
  inline static void printList(list<Flash> flashs, bool imprime_cabecalho = true, bool imprime_id = true);
  inline static void printOne(Flash flash, bool imprime_cabecalho = false, bool imprime_id = true);
  inline static void printWithPrice(Flash flash, ProdutoPreco preco);
};

void FlashView::printList(list<Flash> flashs, bool imprime_cabecalho, bool imprime_id){
  int espaco_inicial = (imprime_id) ? 5 : 0, espaco_meio = 15;

  //CABEÇALHO
  if(imprime_cabecalho){
    cout << setw(espaco_inicial) << ((imprime_id) ?  "Id" : "")
    << setw(espaco_meio) << "Marca"
    << setw(espaco_meio) << "Modelo"
    << setw(espaco_meio) << "Peso"

    << endl << endl;
  }

  //CORPO
  for (auto c : flashs){
    cout << setw(espaco_inicial) << ((imprime_id) ? std::to_string(c.getId()) : "")
      << setw(espaco_meio) << c.getMarca()
      << setw(espaco_meio) << c.getModelo()
      << setw(espaco_meio) << c.getPeso() << "g"

      << endl;
  }
  cout << endl;
}

void FlashView::printOne(Flash flash, bool imprime_cabecalho, bool imprime_id){
  if(flash.getId() == 0){
    cout << "Flash não encontrado!\n";
    return;
  }

  list<Flash> uma_so;
  uma_so.push_back(flash);
  printList(uma_so, imprime_cabecalho, imprime_id);

}

void FlashView::printWithPrice(Flash flash, ProdutoPreco preco){
  int espaco_inicial = 5, espaco_meio = 15;
  
  cout << setw(espaco_inicial) << flash.getMarca()
      << setw(espaco_meio) << flash.getModelo()
      << setw(espaco_meio) << flash.getPeso() << "g"

      << setw(espaco_meio) << preco.getNovoString()
      << setw(espaco_meio) << preco.getPreco()
      <<endl;
}

#endif
