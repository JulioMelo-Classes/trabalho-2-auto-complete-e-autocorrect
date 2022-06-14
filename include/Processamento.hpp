#ifndef Processamento_hpp
#define Processamento_hpp

#include <iostream>
#include <vector>
using namespace std;

class Processamento{
    private:
        string m_palavras_ptbr;
        vector<pair<int, string>> m_dados;
    public:
        /**
         * CRIA UM CONSTRUTOR PROCESSAMENTO QUE RECEBE O NOME DO ARQUIVO COM A BASE DE PALAVRAS 
         * @param palavras_ptbr NOME DO ARQUIVO COM A BASE DE PALAVRAS
         */
        Processamento(string palavras_ptbr);

        /**
         * REALIZA A ABERTURA E LEITURA LINHA A LINHA DO ARQUIVO COM A BASE DE PALAVRAS
         */
        void leitura_arquivo();

        /**
         * ORDENAÇÃO DO AUTOCOMPLETE (ORDEM ALFABETICA)
         */
        void ordenacao_autocomplete();

        /**
         * ORDENAÇÃO DO AUTOCORRECT (TAMANHO DA STRING - ORDEM CRESCENTE)
         */
        void ordenacao_autocorrect();

        /**
         * RECEBE A ENTRADA DADA PELO USUARIO NA LEITURA DA ENTRADA E VERIFICA CARACTERE A CARACTERE SE É VÁLIDA, OU SEJA,
         * 1° NÃO POSSUI CARACTERE ESPECIAL;
         * 2° NÃO É VAZIA;
         * 3° NÃO POSSUI NÚMEROS;
         * @param entrada PREFIXO/PALAVRA DADO PELO USUÁRIO
         */
        bool validacao_entrada(string entrada);

        /**
         * ABRE O ARQUIVO E VERIFICA SE É UM ARQUIVO VÁLIDO PARA SER USADO PELO PROGRAMA
         * VERIFICAÇÕES:
         * 1° EXISTÊNCIA DO ARQUIVO;
         * 2° PRESENÇA DE PALAVRA COM CARACTERE ESPECIAL;
         * 3° PRESENÇA DE PESO NEGATIVO;
         * @return UM VALOR LÓGICO INDICANDO SE A ENTRADA É VALIDA OU NÃO
         */
        bool validacao_arquivo();

        /**
         * GETTER DA BASE DE PALAVRAS GERAL DO PROGRAMA
         * @return VETOR CONTENDO A BASE GERAL DE PALAVRAS E SEUS RESPECTIVOS PESOS
         */
        vector<pair<int, string>> get_dados();
};

#endif
