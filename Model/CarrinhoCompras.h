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
    bool validateLente(Lente lente);
    bool validateFlash(Flash flash);
    bool validateTripe(Tripe tripe);
    float getValorTotal();
};

#endif