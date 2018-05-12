#include "ProdutoPreco.h"

ProdutoPreco::ProdutoPreco(){
  Id = 0;
  Fk_Produto = 0;
  Tipo_Produto = "";
  Quantidade = 0;
  Preco = 0.0; // €
  Novo = true;
}
ProdutoPreco::ProdutoPreco(int id, int fk_Produto, string tipo_Produto, int quantidade, float preco, bool novo){
  Id = id;
  Fk_Produto = fk_Produto;
  Tipo_Produto = tipo_Produto;
  Quantidade = quantidade;
  Preco = preco;
  Novo = novo;
}
ProdutoPreco::ProdutoPreco(ProdutoPreco const &ProdPreco){
  Id = ProdPreco.Id;
  Fk_Produto = ProdPreco.Fk_Produto;
  Tipo_Produto = ProdPreco.Tipo_Produto;
  Quantidade = ProdPreco.Quantidade;
  Preco = ProdPreco.Preco;
  Novo = ProdPreco.Novo;
}

//GETTERS
int ProdutoPreco::getId(){
  return Id;
}
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
string ProdutoPreco::getNovoString(){
  return (Novo) ? "Novo" : "Usado";;
}
string ProdutoPreco::getAllInfo(){
  string novo = getNovoString();
  return "(" + std::to_string(Fk_Produto) + "): " + Tipo_Produto + " qtd: " +std::to_string(Quantidade) + " " + std::to_string(Preco) + "€" + novo;
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
