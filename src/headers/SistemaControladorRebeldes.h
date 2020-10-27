#ifndef SISTEMA_COMTROLADOR_REBELDES
#define SISTEMA_COMTROLADOR_REBELDES

#include "arvore_binaria.h"
#include <vector>

class SistemaControladorRebeldes {
    private:
    ArvoreBinaria arvore;
    public:
    SistemaControladorRebeldes();
    void AdicionaPalavra(TipoChave palavra);
    void SubstituiPalavra(TipoChave palavra_antiga,TipoChave palavra_nova);
    std::string Encripta(int n_palavras, std::vector<TipoChave> palavras);
    std::string Desencripta(int n_codigos, std::vector<int> codigos);
    void ImprimePreOrder();
};

#endif