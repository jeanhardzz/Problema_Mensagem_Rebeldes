#ifndef TIPOITEM
#define TIPOITEM

#include <string>

typedef std::string TipoChave; // TipoChave é um inteiro

class TipoItem{
    private:
        TipoChave chave;
        // outros membros
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();    
};

#endif