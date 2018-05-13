#ifndef TripeView_CPP
#define TripeView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/Tripe.h"

using namespace std;

class TripeView {
public:
  inline static void printList(list<Tripe> tripes, bool imprime_cabecalho = true, bool imprime_id = true);
  inline static void printOne(Tripe tripe, bool imprime_cabecalho = false, bool imprime_id = true);
  inline static void printWithPrice(Tripe tripe, ProdutoPreco preco);
};

void TripeView::printList(list<Tripe> tripes, bool imprime_cabecalho, bool imprime_id){
  int espaco_inicial = (imprime_id) ? 5 : 0, espaco_meio = 15;

  //CABEÇALHO
  if(imprime_cabecalho){
    cout << setw(espaco_inicial) << ((imprime_id) ?  "Id" : "")
    << setw(espaco_meio) << "Marca"
    << setw(espaco_meio) << "Modelo"
    << setw(espaco_meio) << "Peso"
    << setw(espaco_meio) << "Carga_max"

    << endl << endl;
  }

  //CORPO
  for (auto c : tripes){
    cout << setw(espaco_inicial) << ((imprime_id) ? std::to_string(c.getId()) : "")
      << setw(espaco_meio) << c.getMarca()
      << setw(espaco_meio) << c.getModelo()
      << setw(espaco_meio) << c.getPeso() << "g"
      << setw(espaco_meio) << c.getCarga_max() << "g"

      << endl;
  }
  cout << endl;
}

void TripeView::printOne(Tripe tripe, bool imprime_cabecalho, bool imprime_id){
  if(tripe.getId() == 0){
    cout << "Tripe não encontrado!\n";
    return;
  }

  list<Tripe> uma_so;
  uma_so.push_back(tripe);
  printList(uma_so, imprime_cabecalho, imprime_id);

}

void TripeView::printWithPrice(Tripe tripe, ProdutoPreco preco){
  int espaco_inicial = 5, espaco_meio = 15;
  
  cout << setw(espaco_inicial) << tripe.getMarca()
      << setw(espaco_meio) << tripe.getModelo()
      << setw(espaco_meio) << "max: " << tripe.getCarga_max() << "g"
      << setw(espaco_meio) << "(" << tripe.getPeso() << "g)"

      << setw(espaco_meio) << preco.getNovoString()
      << setw(espaco_meio) << preco.getPreco()
      <<endl;
}
#endif
