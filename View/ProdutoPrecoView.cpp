#ifndef ProdutoPrecoView_CPP
#define ProdutoPrecoView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/ProdutoPreco.h"

using namespace std;

class ProdutoPrecoView {
public:
  inline static void printList(list<ProdutoPreco> precos, bool imprime_cabecalho = true, bool imprime_id = true);
  inline static void printOne(ProdutoPreco preco, bool imprime_cabecalho = false, bool imprime_id = true);
  inline static ProdutoPreco readOne(int fk, string tipo);
};

void ProdutoPrecoView::printList(list<ProdutoPreco> precos, bool imprime_cabecalho, bool imprime_id){
  int espaco_inicial = (imprime_id) ? 5 : 0, espaco_meio = 15;

  //CABEÇALHO
  if(imprime_cabecalho){
    cout << setw(espaco_inicial) << ((imprime_id) ? "Id" : "")
    // << setw(espaco_meio) << "Tipo do Produto"
    << setw(espaco_meio) << "Estado"
    << setw(espaco_meio) << "Quantidade"
    << setw(espaco_meio) << "Preço"

    << endl << endl;
  }

  //CORPO
  for (auto c : precos){
    cout << setw(espaco_inicial) << ((imprime_id) ? std::to_string(c.getId()) : "")
      // << setw(espaco_meio) << c.getTipo_Produto()
      << setw(espaco_meio) << c.getNovoString()
      << setw(espaco_meio) << c.getQuantidade()
      << setw(espaco_meio) << c.getPreco() << "€"

      << endl;
  }
  cout << endl;
}

void ProdutoPrecoView::printOne(ProdutoPreco preco, bool imprime_cabecalho, bool imprime_id){
  if(preco.getId() == 0){
    cout << "Preço não encontrada!\n";
    return;
  }

  list<ProdutoPreco> uma_so;
  uma_so.push_back(preco);
  printList(uma_so, imprime_cabecalho, imprime_id);

}

ProdutoPreco ProdutoPrecoView::readOne(int fk, string tipo){
  ProdutoPreco preco = ProdutoPreco();
  string str; int inteiro = 0;

  preco.setFk_Produto(fk);
  preco.setTipo_Produto(tipo);
  
  cout <<  "Entre com a quantidade: ";
  cin >> inteiro;
  preco.setQuantidade(inteiro);

  cout <<  "Entre com 1 se for novo: ";
  cin >> inteiro;
  preco.setNovo(inteiro == 1);

  cout <<  "Entre com o valor: ";
  float valor = 0;
  cin >> valor;
  preco.setPreco(valor);

  return preco;
}

#endif
