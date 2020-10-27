#include "headers/SistemaControladorRebeldes.h"

SistemaControladorRebeldes::SistemaControladorRebeldes(){

}

void SistemaControladorRebeldes::AdicionaPalavra(TipoChave palavra){
    TipoItem item;
    item.SetChave(palavra);
    arvore.Insere(item);
}

void SistemaControladorRebeldes::ImprimePreOrder(){
    arvore.ImprimePreOrder();
}

void SistemaControladorRebeldes::SubstituiPalavra(TipoChave palavra_antiga,TipoChave palavra_nova){
    TipoItem remove,insere;

    remove = arvore.Pesquisa(palavra_antiga);
    arvore.Remove(remove.GetChave());

    insere.SetChave(palavra_nova);

    arvore.Insere(insere);

}

std::string SistemaControladorRebeldes::Encripta(int n_palavras, std::vector<TipoChave> palavras){
    std::string codigo="";
    for(int i=0;i<n_palavras;i++){        
        codigo += std::to_string(arvore.BuscaNumeroPreOrder(palavras[i]));
        codigo += " ";
    }
    return codigo;
}