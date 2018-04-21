#include "ProdutoPreco.h"

ProdutoPreco::ProdutoPreco(){
  Quantidade = 0;
  Preco = 0.0; // €
  Novo = true;
}
ProdutoPreco::ProdutoPreco(int fk_Produto, string tipo_Produto, int quantidade, float preco, bool novo){
  Fk_Produto = fk_Produto;
  Tipo_Produto = tipo_Produto;
  Quantidade = quantidade;
  Preco = preco;
  Novo = novo;
}
ProdutoPreco::ProdutoPreco(ProdutoPreco const &ProdPreco){
  Fk_Produto = ProdPreco.Fk_Produto;
  Tipo_Produto = ProdPreco.Tipo_Produto;
  Quantidade = ProdPreco.Quantidade;
  Preco = ProdPreco.Preco;
  Novo = ProdPreco.Novo;
}

//GETTERS
int ProdutoPreco::getFk_Produto(){
  return Fk_Produto;
}
string ProdutoPreco::getTipo_Produto(){
  return Tipo_Produto;
}
int ProdutoPreco::getQuantidade(){
  return Quantidade;
}
float ProdutoPreco::getPreco(){
  return Preco;
}
bool ProdutoPreco::getNovo(){
  return Novo;
}

//SETTERS
void ProdutoPreco::setFk_Produto(int fk){
  Fk_Produto = fk;
}
void ProdutoPreco::setTipo_Produto(string tipo){
  Tipo_Produto = tipo;
}
void ProdutoPreco::setQuantidade(int qntd){
  Quantidade = qntd;
}
void ProdutoPreco::setPreco(int preco){
  Preco = preco;
}
void ProdutoPreco::setNovo(bool novo){
  Novo = novo;
}
