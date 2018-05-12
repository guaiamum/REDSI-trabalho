#ifndef CarrinhoComprasView_CPP
#define CarrinhoComprasView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/CarrinhoCompras.h"
// OUTRAS VIEWS
#include "CameraView.cpp"
#include "LenteView.cpp"
#include "ProdutoPrecoView.cpp"

using namespace std;

class CarrinhoComprasView {
public:
  inline static void printProducts(CarrinhoCompras carrinho, bool imprime_cabecalho = true);
};

void CarrinhoComprasView::printProducts(CarrinhoCompras carrinho, bool imprime_cabecalho){
  int espaco_inicial = 5, espaco_meio = 15;

  CameraView::printOne(carrinho.camera, false, false);
  list<ProdutoPreco>::iterator it = carrinho.precos.begin();
  ProdutoPrecoView::printOne(*it, false, false);
  LenteView::printOne(carrinho.lente, false, false);
  
  cout << endl;
}

#endif
/*
  CarrinhoCompras();
  Camera camera;
  Lente lente;
  Flash flash;
  Tripe tripe;
  list<ProdutoPreco> precos;
  bool validateLente(Lente lente);
  bool validateFlash(Flash flash);
  bool validateTripe(Tripe tripe);
  float getValorTotal();
*/