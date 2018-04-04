#ifndef ProdutoPreco_H
#define ProdutoPreco_H

#include <string>

using namespace std;

class ProdutoPreco {
  string Fk_Produto;
  string Tipo_Produto;
  int Quantidade;
  float Preco; // €
  bool Novo;
public:
  ProdutoPreco();
  ProdutoPreco(string Fk_Produto, string Tipo_Produto, int Quantidade, float Preco, bool Novo);
  ProdutoPreco(ProdutoPreco const &ProdPreco);
  //GETTERS
  //SETTERS
  void setFk_Produto(string fk);
  void setTipo_Produto(string tipo);
  void setQuantidade(int qntd);
  void setPreco(int preco);
  void setNovo(bool novo);
};

#endif
