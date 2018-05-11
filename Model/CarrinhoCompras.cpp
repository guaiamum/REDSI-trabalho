#include "CarrinhoCompras.h"

CarrinhoCompras::CarrinhoCompras(){
    camera = Camera();
    lente = Lente();
    flash = Flash();
    tripe = Tripe();
}

bool CarrinhoCompras::validateLente(Lente lente){
    return (lente.getMarca() == camera.getMarca());
}

bool CarrinhoCompras::validateFlash(Flash flash){
    return (flash.getMarca() == camera.getMarca());
}

bool CarrinhoCompras::validateTripe(Tripe tripe){
    int pesoTotal = 0; 
    
    pesoTotal += camera.getPeso();
    pesoTotal += lente.getPeso();
    pesoTotal += flash.getPeso();

    return tripe.getCarga_max() >= pesoTotal;
}

float CarrinhoCompras::getValorTotal(){
    return 1;
}