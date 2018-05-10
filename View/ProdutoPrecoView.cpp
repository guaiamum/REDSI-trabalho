#ifndef ProdutoPrecoView_CPP
#define ProdutoPrecoView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/ProdutoPreco.h"

using namespace std;

class ProdutoPrecoView {
public:
  inline static void printList(list<ProdutoPreco> precos, bool com_cabecalho = true);
  inline static void printOne(ProdutoPreco preco);
};

void ProdutoPrecoView::printList(list<ProdutoPreco> precos, bool com_cabecalho){
  int espaco_inicial = 5, espaco_meio = 15;

  //CABEÇALHO
  if(com_cabecalho){
  cout << setw(espaco_inicial) << "Id"
    // << setw(espaco_meio) << "Tipo do Produto"
    << setw(espaco_meio) << "Estado"
    << setw(espaco_meio) << "Quantidade"
    << setw(espaco_meio) << "Preço(€)"

    << endl << endl;
  }

  //CORPO
  for (auto c : precos){
    cout << setw(espaco_inicial) << c.getId()
      // << setw(espaco_meio) << c.getTipo_Produto()
      << setw(espaco_meio) << c.getNovoString()
      << setw(espaco_meio) << c.getQuantidade()
      << setw(espaco_meio) << c.getPreco()

      << endl;
  }
  cout << endl;
}

void ProdutoPrecoView::printOne(ProdutoPreco preco){
  if(preco.getId() == 0){
    cout << "Preço não encontrada!\n";
    return;
  }

  list<ProdutoPreco> uma_so;
  uma_so.push_back(preco);
  printList(uma_so, false);

}

#endif
