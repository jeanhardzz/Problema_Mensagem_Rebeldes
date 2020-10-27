#ifndef ARVORE_BINARIA_PESQUISA
#define ARVORE_BINARIA_PESQUISA

#include "tipoitem.h"
#include "tipono.h"

class ArvoreBinaria{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(TipoItem item);//
        void Caminha(int tipo);
        TipoItem Pesquisa(TipoChave chave);//
        void Remove(TipoChave chave);//
        void Limpa();
        void ImprimePreOrder();
        int BuscaNumeroPreOrder(TipoChave palavra);
        std::string BuscaPalavraPreOrder(int codigo);
    private:
        void InsereRecursivo(TipoNo* &p, TipoItem item);//
        void ApagaRecursivo(TipoNo* p);
        TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave);//
        void RemoveRecursivo(TipoNo* &p, TipoChave chave);//
        void Antecessor(TipoNo* q, TipoNo* &r);//        
        void PreOrdem(TipoNo* p); 
        void BuscaNumeroPreOrderRecursivo(TipoNo *p,TipoChave palavra);       
        void BuscaPalavraPreOrderRecursivo(TipoNo *p,int codigo); 
        TipoNo *raiz;
        int count,achei;
        TipoItem aux;
};

#endif