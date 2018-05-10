#ifndef ProdutoPreco_H
#define ProdutoPreco_H

#include <string>

using namespace std;

class ProdutoPreco {
  int Id;
  int Fk_Produto;
  string Tipo_Produto;
  int Quantidade;
  float Preco; // €
  bool Novo;
public:
  ProdutoPreco();
  ProdutoPreco(int id, int Fk_Produto, string Tipo_Produto, int Quantidade, float Preco, bool Novo);
  ProdutoPreco(ProdutoPreco const &ProdPreco);
  //GETTERS
  int getId();
  int getFk_Produto();
  string getTipo_Produto();
  int getQuantidade();
  float getPreco();
  bool getNovo();
  string getNovoString();
  string getAllInfo();
  //SETTERS
  void setFk_Produto(int fk);
  void setTipo_Produto(string tipo);
  void setQuantidade(int qntd);
  void setPreco(int preco);
  void setNovo(bool novo);
};

#endif
