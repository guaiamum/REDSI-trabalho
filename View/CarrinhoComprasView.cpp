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
  //INTRO
  cout << "A seguir podes ver o seu carrinho com os produtos selecionados!\n";

  //CAMERA
  ProdutoPreco it = carrinho.getPrecoByTipo("CAMERA");
  cout << "Camera: ";
  CameraView::printWithPrice(carrinho.camera, it);

  //LENTE
  it = carrinho.getPrecoByTipo("LENTE");
  if (it.getId() == 0) {
    cout << "Lente: ";
    LenteView::printWithPrice(carrinho.lente, it);
  }

  //FLASH
  it = carrinho.getPrecoByTipo("FLASH");
  if (it.getId() == 0) {
    cout << "Flash: ";
    FlashView::printWithPrice(carrinho.flash, it);
  }
  //TRIPE
  it = carrinho.getPrecoByTipo("TRIPE");
  if (it.getId() == 0) {
    cout << "Tripe: ";
    TripeView::printWithPrice(carrinho.tripe, it);
  }
  
  cout << endl;
}

#endif