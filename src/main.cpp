#include <iostream>

#include "headers/SistemaControladorRebeldes.h"
#include <vector>

int main(){      
  SistemaControladorRebeldes rebelde;
    
  char operacao;
  while(std::cin>>operacao){
    if(operacao=='i'){ //Adiciona um palavra a arvore binaria
        TipoChave palavra;
        std::cin>>palavra;
        rebelde.AdicionaPalavra(palavra);
        //std::cout<<"opcao i"<<std::endl;
    }
    if(operacao=='s'){ //Substituir uma palavra (pesquisa,deleta,adiciona)
        TipoChave palavra_antiga,palavra_nova;
        std::cin>>palavra_antiga;
        std::cin>>palavra_nova;        
        rebelde.SubstituiPalavra(palavra_antiga,palavra_nova);
        //std::cout<<"opcao s"<<std::endl;
    }
    if(operacao=='e'){ //encripitar        
        int n_palavras;
        std::vector<TipoChave> palavras;
        std::cin>>n_palavras;
         
        TipoChave palavra;
        for(int i=0;i<n_palavras;i++){            
            std::cin>>palavra;
            palavras.push_back(palavra);
        }
        std::string codigo = rebelde.Encripta(n_palavras,palavras);
        std::cout<<"\n"<<codigo<<std::endl;
        //std::cout<<"opcao e"<<std::endl;
    }
    if(operacao=='d'){ //desencripitar
        std::cout<<"opcao d"<<std::endl;
    }
    if(operacao=='a'){ //mostra em preorder      
        rebelde.ImprimePreOrder();
        //std::cout<<"\nopcao a"<<std::endl;
    }    
  }
   return 0;
}
