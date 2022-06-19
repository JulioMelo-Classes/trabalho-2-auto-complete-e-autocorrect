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
         * ARMAZENA AS PALAVRAS DO VETOR DE PARES COM AS PALAVRAS DE TAMANHO S OU S+1 QUE TIVEREM AS MENORES 
         * DISTANCIAS DE EDIÇÃO NO VETOR DE PARES COM AS PALAVRAS EM POTENCIAL PARA O AUTOCORRECT
         * @param p REFERÊNCIA DA CLASSE PROCESSAMENTO
         * @param prefixo PREFIXO/PALAVRA DADO PELO USUÁRIO
         */ 
        void auto_correct(Processamento* p, std::string prefixo);

        /**
        * CALCULA A DISTÂNCIA DE LEVENSHTEIN (DISTÂNCIA DE EDIÇÃO)
        * @param str1 PRIMEIRA PALAVRA
        * @param str2 SEGUNDA PALAVRA
        * @param len_str1 TAMANHO DA 1° PALAVRA
        * @param len_str2 TAMANHO DA 2° PALAVRA
        * @return UM INTEIRO REPRESENTANDO A QUANTIDADE MINIMA DE OPERAÇÕES (INSERÇÃO, REMOÇÃO, SUBSTITUIÇÃO) PARA TRANSFORMAR str1 EM str2
        */
        int dist_levenshtein(std::string str1, std::string str2, int len_str1, int len_str2);

        /**
         * GETTER DAS PALAVRAS EM POTENCIAL PARA O AUTOCORRECT
         * @return VETOR CONTENDO AS PALAVRAS DO AUTOCORRECT
         */
        std::vector<std::pair<int, std::string>> get_dados_correct();
};

#endif