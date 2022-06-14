#ifndef Autocorrect_hpp
#define Autocorrect_hpp

#include <iostream>
#include <vector>
#include "Processamento.hpp"
class Autocorrect{
    private:
        std::vector<std::pair<int, std::string>> m_dados_correct;
        int m_len_prefixo;
    public:
        /**
         * CRIA UM CONSTRUTOR AUTOCORRECT QUE RECEBE O TAMANHO DO PREFIXO/PALAVRA DADO PELO USUÁRIO 
         * @param len_prefixo TAMANHO DO PREFIXO/PALAVRA DADO PELO USUÁRIO
         */
        Autocorrect(int len_prefixo);

        /**
         * PEGA DA BASE DE DADOS GERAL AS PALAVRAS EM POTENCIAL PARA O AUTOCORRECT E ARMAZENA NO ATRIBUTO m_dados_correct
         * @param p REFERÊNCIA DA CLASSE PROCESSAMENTO
         * @param prefixo PREFIXO/PALAVRA DADO PELO USUÁRIO
         */ 
        void auto_correct(Processamento* p, std::string prefixo);

        /**
         * GETTER DAS PALAVRAS EM POTENCIAL PARA O AUTOCORRECT
         * @return VETOR CONTENDO AS PALAVRAS DO AUTOCORRECT
         */
        std::vector<std::pair<int, std::string>> get_dados_correct();
};

#endif