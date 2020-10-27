#include "headers/arvore_binaria.h"

ArvoreBinaria::ArvoreBinaria(){
    raiz = 0;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = 0;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p!=0){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

TipoItem ArvoreBinaria::Pesquisa(TipoChave chave) {
    return PesquisaRecursivo(raiz, chave);
}


TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoChave chave) {
    TipoItem aux;
    if (no == 0) {
        aux.SetChave(""); // Flag para item não presente
        return aux;
    }
    if (chave < no->item.GetChave())
        return PesquisaRecursivo(no->esq, chave);
    else if (chave>no->item.GetChave())
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}

void ArvoreBinaria::Insere(TipoItem item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
    if(p==0){
        p = new TipoNo();
        p->item = item;
    }
    else{
        if(item.GetChave().compare(p->item.GetChave()) < 0)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::Remove(TipoChave chave) {
    return RemoveRecursivo(raiz, chave);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, TipoChave chave){
    TipoNo *aux;
    if (no == 0) {
        throw("Item nao está presente");
    }
    if (chave.compare(no->item.GetChave()) < 0 )
        return RemoveRecursivo(no->esq, chave);
    else if (chave.compare(no->item.GetChave())> 0)
        return RemoveRecursivo(no->dir, chave);
    else {
        if (no->dir == 0) {
            aux = no;
            no = no->esq;
            delete(aux);
        }
        else if(no->esq == 0) {
            aux = no;
            no = no->dir;
            delete(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != 0) {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    delete(q);
}

void ArvoreBinaria::ImprimePreOrder(){
    this->PreOrdem(raiz);
}

void ArvoreBinaria::PreOrdem(TipoNo *p){
    //visita o no, depois os filhos da esquerda e depois os da direita
    if(p!=0){
        p->item.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

int ArvoreBinaria::BuscaNumeroPreOrder(TipoChave palavra){
    this->count=0;
    this->achei=0;
    BuscaNumeroPreOrderRecursivo(raiz,palavra);
    return count;
}

void ArvoreBinaria::BuscaNumeroPreOrderRecursivo(TipoNo *p,TipoChave palavra){
    //visita o no, depois os filhos da esquerda e depois os da direita             
    if(p!=0){
        count++;
        if(palavra.compare(p->item.GetChave())==0){
            this->achei=1;           
        }
        if(achei==0)
            BuscaNumeroPreOrderRecursivo(p->esq,palavra);
        if(achei==0)
            BuscaNumeroPreOrderRecursivo(p->dir,palavra);
    }    
}

std::string ArvoreBinaria::BuscaPalavraPreOrder(int codigo){
    this->count=codigo;
    this->achei=0;
    BuscaPalavraPreOrderRecursivo(raiz,codigo);
    return aux.GetChave();
}

void ArvoreBinaria::BuscaPalavraPreOrderRecursivo(TipoNo *p,int codigo){
    //visita o no, depois os filhos da esquerda e depois os da direita
    if(p!=0){
        count--;
        if(count==0){
            aux = p->item;           
        }
        if(count!=0)
            BuscaPalavraPreOrderRecursivo(p->esq,codigo);
        if(count!=0)
            BuscaPalavraPreOrderRecursivo(p->dir,codigo);
    } 
} 

