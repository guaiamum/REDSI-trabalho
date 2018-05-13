#include "CarrinhoCompras.h"
// #include <iostream>

CarrinhoCompras::CarrinhoCompras(){
    camera = Camera();
    lente = Lente();
    flash = Flash();
    tripe = Tripe();
}

ProdutoPreco CarrinhoCompras::getPrecoByTipo(string tipo_produto){
    std::list<ProdutoPreco>::iterator first = precos.begin();
    std::list<ProdutoPreco>::iterator last = precos.end();

    while (first != last) {
        if (first->getTipo_Produto() == tipo_produto) return *first;
        ++first;
    }
  return *last;
}

bool CarrinhoCompras::validatePreco(ProdutoPreco preco, string tipo_produto, int id){
    // cout << preco.getTipo_Produto() << endl << preco.getFk_Produto;
    return (preco.getTipo_Produto() == tipo_produto && preco.getFk_Produto() == id);
}


bool CarrinhoCompras::validateLente(Lente lente){
    return (lente.getMarca() == camera.getMarca());
}

bool CarrinhoCompras::validateFlash(Flash flash){
    return (flash.getMarca() == camera.getMarca());
}

bool CarrinhoCompras::validateTripe(Tripe tripe){
    return tripe.getCarga_max() >= getCarga();
}

float CarrinhoCompras::getPrecoTotal(){
    float precoTotal = 0; 
    
    for(auto p : precos){
        precoTotal += p.getPreco();
    }
    
    return precoTotal;
}

int CarrinhoCompras::getCarga(){
    int pesoTotal = 0; 
    
    pesoTotal += camera.getPeso();
    pesoTotal += lente.getPeso();
    pesoTotal += flash.getPeso();
    
    return pesoTotal;
}