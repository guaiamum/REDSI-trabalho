#ifndef CarrinhoCompras_H
#define CarrinhoCompras_H

#include <list>
#include "Camera.h"
#include "Lente.h"
#include "Flash.h"
#include "Tripe.h"
#include "ProdutoPreco.h"

class CarrinhoCompras {
public:
    CarrinhoCompras();
    Camera camera;
    Lente lente;
    Flash flash;
    Tripe tripe;
    list<ProdutoPreco> precos;
    // METHODS
    ProdutoPreco getPrecoByTipo(string tipo_produto);
    bool validatePreco(ProdutoPreco preco, string tipo_produto, int id);
    bool validateLente(Lente lente);
    bool validateFlash(Flash flash);
    bool validateTripe(Tripe tripe);
    float getPrecoTotal();
    int getCarga();
};

#endif