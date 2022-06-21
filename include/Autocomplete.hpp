#ifndef Autocomplete_hpp
#define Autocomplete_hpp

#include <iostream>
#include <vector>
#include "Processamento.hpp"

class Autocomplete{
    private:
        std::vector<std::pair<int, std::string>> m_dados_autocomplete; //<! VETOR CONTENDO OS DADOS DO AUTOCOMPLETE
        std::string m_prefixo; //<! PREFIXO DADO PELO USUÁRIO
    public:
        /**
         * CRIA UM CONSTRUTOR AUTOCOMPLETE QUE RECEBE A PALAVRA OU PREFIXO DADO PELO USUÁRIO 
         * @param prefixo Palavra ou parte dela dada pelo usuário
         */
        Autocomplete(std::string prefixo);

        /**
         * ARMAZENA AS PALAVRAS EM POTENCIAL PARA O AUTOCOMPLETE MAIS SIGNIFICATIVAS, OU SEJA, AS DE MAIOR PESO
         * @param p REFERÊNCIA DA CLASSE PROCESSAMENTO
         */ 
        void auto_complete(Processamento* p);

        /**
         * EXTRAI AS PALAVRAS MAIS SIGINIFCATIVAS DO VETOR DE PARES COM TODAS AS PALAVRAS EM POTENCIAL PARA O AUTOCOMPLETE
         * @return VETOR CONTENDO AS PALAVRAS MAIS SIGNIFICATIVAS (COM OS MAIORES PESOS) DO AUTOCOMPLETE
         */
        std::vector<std::pair<int, std::string>> dados_autocomplete_interface();


};

#endif