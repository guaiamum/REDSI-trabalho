#include "CarrinhoCompras.h"

CarrinhoCompras::CarrinhoCompras(){
    camera = Camera();
    lente = Lente();
    flash = Flash();
    tripe = Tripe();
}

bool CarrinhoCompras::validatePreco(string tipo_preco,string tipo_produto){
    return (tipo_preco == tipo_produto);
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