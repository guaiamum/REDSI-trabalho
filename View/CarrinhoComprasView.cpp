#ifndef CarrinhoComprasView_CPP
#define CarrinhoComprasView_CPP

#include <iostream>
#include <iomanip>
#include <list>
#include "../Model/CarrinhoCompras.h"
// OUTRAS VIEWS
#include "CameraView.cpp"
#include "LenteView.cpp"
#include "FlashView.cpp"
#include "TripeView.cpp"
#include "ProdutoPrecoView.cpp"

using namespace std;

class CarrinhoComprasView {
public:
  inline static void printProducts(CarrinhoCompras carrinho, bool imprime_cabecalho = true);
};

/**
    Prints all items in the shopping cart.

    @param CarrinhoCompras carrinho, bool imprime_cabecalho.
    @return nothing .
*/
void CarrinhoComprasView::printProducts(CarrinhoCompras carrinho, bool imprime_cabecalho){
  int espaco_inicial = 5, espaco_meio = 15;
  list<ProdutoPreco>::iterator it = carrinho.precos.begin();

  cout << "A seguir podes ver o seu carrinho com os produtos selecionados!\n";

  //CAMERA
  CameraView::printOne(carrinho.camera, false, false);
  ProdutoPrecoView::printOne(*it, false, false);
  //LENTE
  LenteView::printOne(carrinho.lente, false, false);
  ProdutoPrecoView::printOne(*++it, false, false);
  //FLASH
  FlashView::printOne(carrinho.flash, false, false);
  ProdutoPrecoView::printOne(*++it, false, false);
  //TRIPE
  TripeView::printOne(carrinho.tripe, false, false);
  ProdutoPrecoView::printOne(*++it, false, false);
  
  cout << endl;
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
}

#endif