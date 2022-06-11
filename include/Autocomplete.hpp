#ifndef Autocomplete_hpp
#define Autocomplete_hpp

#include <iostream>
#include <vector>
#include "Processamento.hpp"

class Autocomplete{
    private:
        std::vector<std::pair<int, std::string>> m_dados_com_prefixo; //<! VETOR CONTENDO OS DADOS DO AUTOCOMPLETE
        std::string m_prefixo; //<! PREFIXO DADO PELO USUÁRIO
    public:
        /**
         * CRIA UM CONSTRUTOR AUTOCOMPLETE QUE RECEBE A PALAVRA OU PREFIXO DADO PELO USUÁRIO 
         * @param prefixo Palavra ou parte dela dada pelo usuário
         */
        Autocomplete(std::string prefixo);

        /**
         * PEGA DA BASE DE DADOS GERAL AS PALAVRAS EM POTENCIAL PARA O AUTOCOMPLETE E ARMAZENA NO ATRIBUTO m_dados_com_prefixo
         * @param p REFERÊNCIA DA CLASSE PROCESSAMENTO
         */ 
        void auto_complete(Processamento* p);

        /**
         * GETTER DO VETOR DAS PALAVRAS DO AUTOCOMPLETE
         * @return VETOR CONTENDO AS PALAVRAS DO AUTOCOMPLETE
         */
        std::vector<std::pair<int, std::string>> get_dados_com_prefixo();


};

#endif